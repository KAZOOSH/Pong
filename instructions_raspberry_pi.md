# Complete instructions raspberry pi


## Install raspbian

See [guide](https://www.raspberrypi.org/documentation/installation/installing-images/)

### Update the system

```
sudo apt-get clean
sudo apt-get update
sudo apt-get upgrade
```

### Prepare system for Pong

Go to *settings->pi-settings* und set video memory to ```512mb```

Set *cli* as startup option to save memory.

## Install Pong

Ether you can choose to *compile the sourcecode yourself* or *install the binary*

### Install from binary

```
wget https://github.com/KAZOOSH/Pong/releases/download/0.1-preRelease/Pong_0.1-preRelease_raspbian.tar.gz
tar -xvkzf p.tar.gz
```


### Compile form source

Clone repository

```
git clone https://github.com/KAZOOSH/Pong
```

Download and extract openFrameworks v0.9.3 in Pong repository

```
wget http://www.openframeworks.cc/versions/v0.9.3/of_v0.9.3_linuxarmv6l_release.tar.gz
tar -xvkzf of_v0.9.3_linuxarmv6l_release.tar.gz
mv -n of_v0.9.3_linuxarmv6l_release/* Pong/
mv -n of_v0.9.3_linuxarmv6l_release/addons/* Pong/addons
rm -R of_v0.9.3_linuxarmv6l_release
```

Prepare openFrameworks (see [instructions pi](http://openframeworks.cc/setup/raspberrypi/)).

Install dependencies

```
cd /home/pi/openFrameworks/scripts/linux/debian
sudo ./install_dependencies.sh
```

make

```
make Release -C /home/pi/openFrameworks/libs/openFrameworksCompiled/project -j4
```

compile Pong

```
cd /home/pi/openFrameworks/apps/Pong/pong
make
make run
```

## Set USB controller as persistent device 

We have to identify the two controllers first. With ```lsusb``` you get a list of the connected Serial Devices. Connect the Arduino for one controller and list the devices. You get a list like

```
~ # lsusb
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 001 Device 011: ID 0403:6001 Arduino UNO R5
[...]
```

Enter ```/dev/tty``` and tab to get the device names. The Arduino should be named like ```ttyAM...```. Then we get the details of the device by entering

```
udevadm info -a -n /dev/ttyUSB1 | grep '{serial}' | head -n1
udevadm info -a -n /dev/ttyUSB1 | grep '{idVendor}' | head -n1
udevadm info -a -n /dev/ttyUSB1 | grep '{idProduct}' | head -n1
```
Copy all this informations. Go to ```/etc/udev/rules.d``` Create a file named ```99-usb-serial.rules```: 

```
cd /etc/udev/rules.d
sudo nano 99-usb-serial.rules
```

Enter the following line (of course, use your values):

```
SUBSYSTEM=="tty", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6001", ATTRS{serial}=="A6008isP", SYMLINK+="controllerLeft"
```

Do this for all the controllers. With this information you have to edit the *settings.xml*.

```
sudo nano /home/pi/openFrameworks/apps/Pong/pong/bin/data/settings.xml
```

Reset the port values and activate serial control

```xml
<isSerialControl>1</isSerialControl>
<portLeftPaddle>controllerLeft</portLeftPaddle>
<portRightPaddle> controllerRight</portRightPaddle>
```

More information on this at ([persistent USB](http://hintshop.ludvig.co.nz/show/persistent-names-usb-serial-devices/)).

## Install fadeCandy

To interface we need to install the fadeCandy-driver.

```
git clone git://github.com/scanlime/fadecandy

cd fadecandy/server
make submodules
make
```

Copy fcserver for autorun

```
sudo mv fcserver /usr/local/bin
```

## Configure autostart

Copy Pong in *local/bin*

```
cd /usr/local/bin
sudo mkdir Pong
sudo cp -R /home/pi/openFrameworks/apps/Pong/pong/bin/* /usr/local/bin/Pong
```


edit rc.local

```
sudo nano /etc/rc.local
```

Before ```exit 0``` set fcserver and Pong to start

```

#!/bin/sh -e
#
# rc.local
#
# This script is executed at the end of each multiuser runlevel.
# Make sure that the script will "exit 0" on success or any other
# value on error.
#
# In order to enable or disable this script just change the execution
# bits.
#
# By default this script does nothing.
  
/usr/local/bin/fcserver &    # start fcserver  
/usr/local/bin/Pong/pong     # start Pong
  
exit 0
```

Done!






