

#include "FastLED.h"
#include <Keyboard.h>

#define MAX_HELLIGKEIT_STRIPES 180
#define FADE_NEXT_ON_AT 30
#define MIN_HELLIGKEIT_PULSE 100

#define MAX_HELLIGKEIT_CIRCLE 150

#define CIRCLE_SPEED 4
#define STRIPE_SPEED 10



#define NUM_LEDS_circle 24

#define NUM_LEDS_stripe 60
#define START_LED_STRIPE 12

#define DATA_PIN_circle 4

#define NUM_STRIPES 4
#define DATA_PIN_stripe1 5
#define DATA_PIN_stripe2 6
#define DATA_PIN_stripe3 9
#define DATA_PIN_stripe4 8

#define sensor_input 3
#define button_input 12



CRGB leds_circle[NUM_LEDS_circle];
CRGB leds_stripe[NUM_STRIPES][NUM_LEDS_stripe];

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(sensor_input, INPUT);
  pinMode(button_input, INPUT);
  digitalWrite(button_input, HIGH);
  Keyboard.begin();
  //Serial.begin(9600);
  
  FastLED.addLeds<WS2812, DATA_PIN_circle, GRB>(leds_circle, NUM_LEDS_circle);
  FastLED.addLeds<WS2812, DATA_PIN_stripe1, GRB>(leds_stripe[0], NUM_LEDS_stripe);
  FastLED.addLeds<WS2812, DATA_PIN_stripe2, GRB>(leds_stripe[1], NUM_LEDS_stripe);
  FastLED.addLeds<WS2812, DATA_PIN_stripe3, GRB>(leds_stripe[2], NUM_LEDS_stripe);
  FastLED.addLeds<WS2812, DATA_PIN_stripe4, GRB>(leds_stripe[3], NUM_LEDS_stripe);
  clear_display(0);
  clear_display(1);
  FastLED.show();

}

void loop() {
  
  CRGB color_rgb;
  CHSV hsv_color;
  int circle_direction[NUM_LEDS_circle];
  int circle_value[NUM_LEDS_circle];
  int stripe_direction[NUM_LEDS_stripe];
  int stripe_value[NUM_LEDS_stripe];
  int previous_led, touched, ct_fade;
  // read the value from the sensor:

  hsv_color.h=0;
  hsv_color.s=0;
  hsv_color.v=0;



  // Geldeinwurf Kreis dreht sich
  
  for (int ct_x = 0; ct_x < NUM_LEDS_circle; ct_x++)
  {
    circle_value[ct_x]=0;
    circle_direction[ct_x]=0;
  }
  
  circle_direction[0]=1;
  while(digitalRead(sensor_input)) {
    
    for (int ct_x = 0; ct_x < NUM_LEDS_circle; ct_x++)
    {
      if (circle_direction[ct_x]==1) {
        circle_value[ct_x]=circle_value[ct_x]+CIRCLE_SPEED;
      }
      if (circle_direction[ct_x]==2) {
        circle_value[ct_x]=circle_value[ct_x]-CIRCLE_SPEED;
      }

      if (circle_value[ct_x]>MAX_HELLIGKEIT_CIRCLE) {
        circle_direction[ct_x]=2;
      }

      if (circle_value[ct_x]==0) {
        circle_direction[ct_x]=0;
      }

      if ((circle_value[ct_x]>30)&&(circle_direction[ct_x]==1)) {
        if (ct_x==0) {
          previous_led=NUM_LEDS_circle-1;
        }
        else {
          previous_led=ct_x-1;
        }
        circle_direction[previous_led]=1;
      }
      
      
      hsv_color.v=circle_value[ct_x];
      hsv2rgb_rainbow(hsv_color,leds_circle[ct_x]);
    }
    FastLED.show();
  }
 
  clear_display(0);
  FastLED.show();



  // Lade Säule auf
  
  for (int ct_x = START_LED_STRIPE; ct_x < NUM_LEDS_stripe; ct_x++)
  {
    stripe_value[ct_x]=0;
    stripe_direction[ct_x]=0;
  }
  
  stripe_direction[START_LED_STRIPE]=1;
  while(stripe_value[NUM_LEDS_stripe-1]<MAX_HELLIGKEIT_STRIPES) {
    
    for (int ct_x = START_LED_STRIPE; ct_x < NUM_LEDS_stripe; ct_x++)
    {
      if (stripe_direction[ct_x]==1) {
        stripe_value[ct_x]=stripe_value[ct_x]+STRIPE_SPEED;
      }

      if (stripe_value[ct_x]>MAX_HELLIGKEIT_STRIPES) {
        stripe_direction[ct_x]=0;
      }

      if ((stripe_value[ct_x]>FADE_NEXT_ON_AT)&&(stripe_direction[ct_x]==1)) {
        if (ct_x<NUM_LEDS_stripe-1) {
          previous_led=ct_x+1;
        }
        stripe_direction[previous_led]=1;
      }
      
      
      hsv_color.v=stripe_value[ct_x];
      hsv2rgb_rainbow(hsv_color,color_rgb);
      for (int ct_stripe = 0; ct_stripe<NUM_STRIPES;ct_stripe++){
        leds_stripe[ct_stripe][ct_x]=color_rgb;
      }
    }
    FastLED.show();
    
  }

  // Säule ist bereit und pulsiert
  touched=0;
  while(!touched) {
    ct_fade=MAX_HELLIGKEIT_STRIPES;
    while ((!touched)&&(ct_fade>MIN_HELLIGKEIT_PULSE)) {
      hsv_color.v=ct_fade;
      for (int ct_led = START_LED_STRIPE; ct_led < NUM_LEDS_stripe; ct_led++)
      {
        for (int ct_stripe = 0; ct_stripe<NUM_STRIPES;ct_stripe++){
          hsv2rgb_rainbow(hsv_color,leds_stripe[ct_stripe][ct_led]);
        }
        if (!digitalRead(button_input)) {
          touched=1;
        }
      }
      FastLED.show();
      ct_fade--;
    }
    while ((!touched)&&(ct_fade<MAX_HELLIGKEIT_STRIPES)) {
      hsv_color.v=ct_fade;
      for (int ct_led = START_LED_STRIPE; ct_led < NUM_LEDS_stripe; ct_led++)
      {
        for (int ct_stripe = 0; ct_stripe<NUM_STRIPES;ct_stripe++){
          hsv2rgb_rainbow(hsv_color,leds_stripe[ct_stripe][ct_led]);
        }
        if (!digitalRead(button_input)) {
          touched=1;
        }
      }
      FastLED.show();
      ct_fade++;
    }
  }
  Keyboard.print('p');

  for (int ct_x = MAX_HELLIGKEIT_STRIPES; ct_x >= 0; ct_x--)
  {
    hsv_color.v=ct_x;
    for (int ct_led = START_LED_STRIPE; ct_led < NUM_LEDS_stripe; ct_led++)
    {
      for (int ct_stripe = 0; ct_stripe<NUM_STRIPES;ct_stripe++){
        hsv2rgb_rainbow(hsv_color,leds_stripe[ct_stripe][ct_led]);
      }
    }
  FastLED.show();
  }

}


void clear_display(int channel)
{
  int ct_led;

  if (channel==0) {
    for (int ct_x = 0; ct_x < NUM_LEDS_circle; ct_x++)
    {
      leds_circle[ct_x] = CRGB::Black;
    }
  }
  else {
    for (int ct_x = 0; ct_x < NUM_LEDS_stripe; ct_x++)
    {
      for (int ct_stripe = 0; ct_stripe<NUM_STRIPES;ct_stripe++){
        leds_stripe[ct_stripe][ct_x] = CRGB::Black;
      }
    }
  }

}

