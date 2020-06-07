# Home Automation System

Along with the control over electrical appliances of the house, the system makes use of various sensors like Gas, and PIR (passive infrared sensor) used to alert and assist the specially abled people. These sensors sense the change in environment and actuate with a particular action like sending notiﬁcation to user and turning on emergency lights.
The MQ-2 Gas Sensor module detects gas leakage in home and industry. The MQseries of gas sensors use a small heater inside with an electrochemical sensor. A threshold value is set for the sensor during initialization. If the smoke density is greater than the threshold value then the sensor sends the analog signal to the controller. These analog signals are forwarded to analog input of Arduino uno board. This analog signal is converted into digital signals reﬂected by turning on or oﬀ the emergency lights and alarms.
A passive infrared sensor (PIR sensor) is used which is an electronic sensor that measures infrared (IR) light radiating from objects in its ﬁeld of view. It detects the infrared objects within the range of 10m. Mostly used to detect motion the PIR sensor is used here to toggle Lights of a room if it detects any motion in the room. The Sensor automatically instructs the controller to turn oﬀ the Lights if no motion is detected for 30 seconds. This not only minimizes the eﬀort of switching on/oﬀ the lights but also helps save power in case the user forgets to turn the lights oﬀ. The logs of appliances used will be generated at the server for billing algorithms to automatically generate billing reports.

# Technologies used

1. Arduino
2. Things speak server
3. SQL
4. IOT devices.

# Usage

Upload the codes to the MCU device using any ide or the command line interface and you are good to go.

Follow the circuit diagram to support the code configurations.

![alt Circuit diagram](https://github.com/RohanShah27/Home-Automation-System/blob/master/screenshot/cktdiagram.png?raw=true)

# This is how our set up looks

![alt Original Setup](https://github.com/RohanShah27/Home-Automation-System/blob/master/screenshot/raw.png?raw=true)

# Publication

1. Paper published on IJSRD Journal
   http://ijsrd.com/Article.php?manuscript=IJSRDV7I20500
