/**
 * Radsensor
 * für das Pong zum Hechtfest 2016
 *
 * Benötigt:
 * - AS5601-Treiber
 *   https://github.com/bitfasching/AS5601
 *
 * nick@bitfasching.de
 * KAZOOSH!
 */


#include <Arduino.h>
#include <AS5601.h>


// Kalibrierungszeit [ms]
const unsigned int calibrationTime = 10000;

// Sensorrauschunterdrückung (Änderungsschwelle für Positionsübernahme)
const int sensorNoise = 4;


// Magnetsensor vorbereiten
AS5601 Sensor;

// globale Variable für Messwerte
int referenceAngle;

// globale Variablen für Kalibrierungszustand und Startzeitpunkt
enum State { IDLE, WAITING, CALIBRATING, TRACKING } State;
unsigned long startTime;


// Sensor auslesen und Position ermitteln
void updatePosition( int &position )
{
    int newAngle, delta;

    // aktuellen Winkel einlesen
    newAngle = (int) Sensor.getRawAngle();

    // Differenz ermitteln
    delta = newAngle - referenceAngle;

    // Rauschen unterdrücken und kleine Änderungen ignorieren
    if ( abs( delta ) < sensorNoise ) { return; }

    // Überdrehung abfangen
    if ( delta >  2048 ) { delta = delta - 4096; }
    if ( delta < -2048 ) { delta = delta + 4096; }

    // fortlaufenden Winkel weiterzählen
    position = position + delta;

    // Referenzwinkel aktualisieren
    referenceAngle = newAngle;
}

// Nachkalibrierung von Ober- & Untergrenze
bool calibrate( int position, int &top, int &bottom, int &middle, int length )
{
    int offset = 0;

    // Überschreitung?
    if ( position > top )
    {
        // positive Differenz
        offset = position - top;
    }
    // Unterschreitung?
    else if ( position < bottom )
    {
        // negative Differenz
        offset = position - bottom;
    }

    // wenn Anpassung notwendig…
    if ( offset != 0 )
    {
        // beide Grenzen synchron nachführen (hält Weglänge zwischen Grenzen konstant)
        top += offset;
        bottom += offset;

        // Mitte neu berechnen
        middle = bottom + length / 2;
    }
}


// Start
void setup()
{
    // kurz warten und USB einschalten
    delay( 1000 );
    Serial.begin( 115200 );

    // Hallo sagen
    Serial.println( F("[Radsensor Pong 2016]") );

    // Startwinkel setzen
    referenceAngle = (int) Sensor.getRawAngle();
}


// Hauptschleife
void loop()
{
    static int position = 0;
    static int top, bottom, middle, length;

    // Sensor abfragen und Position ermitteln
    updatePosition( position );

    // Weglänge kalibriert?
    if ( State == TRACKING )
    {
        // Nachkalibrierung: Grenzen nachführen
        calibrate( position, top, bottom, middle, length );

        // neuer Wert angefragt?
        if ( Serial.read() != -1 )
        {
            // Position auf ±1024 mappen
            int scaledPosition = (long) ( position - middle ) * 2048 / length;

            // Wert als 16-bit-Wort ausgeben (Big Endian)
            Serial.write( highByte( scaledPosition ) );
            Serial.write( lowByte( scaledPosition ) );
            //Serial.println( scaledPosition );
        }
    }
    // noch nicht kalibriert
    else
    {
        // Kalibrierung noch gar nicht gestartet?
        if ( State == IDLE )
        {
            // beide Grenzen zum Start auf aktuelle Position setzen
            top = position;
            bottom = position;

            // nächster Zustand: Warten auf Bewegung
            State = WAITING;

            // Status ausgeben
            Serial.print( F("Waiting ") );
        }
        // Warten auf Bewegung?
        else if ( State == WAITING )
        {
            // sobald Bewegung stattgefunden hat (also Position verändert wurde)…
            if ( length > 0 )
            {
                // Startzeit festhalten
                startTime = millis();

                // nächster Zustand: Kalibrieren
                State = CALIBRATING;

                // Status ausgeben
                Serial.print( F("Calibrating ") );
            }
        }

        // Obergrenze und Untergrenze ausweiten
        if ( position > top ) { top = position; }
        if ( position < bottom ) { bottom = position; }

        // Gesamtweg und Mitte berechnen
        length = top - bottom;
        middle = bottom + length / 2;

        // Kalibrierungszeit abgelaufen?
        if ( State == CALIBRATING && millis() > startTime + calibrationTime )
        {
            // Kalibrierung für abgeschlossen erklären
            State = TRACKING;

            // Status ausgeben
            Serial.println( F("Tracking") );
        }
    }
}
