# AlarmForce: General Idea

This is a project to intend integrate IOT Solutions in Salesforce. The stack selected:
* IOT Proxy Platform:
    * Thingspeak-> Rest API
*  Hardware:
    * ESP32
         * PIR Sensor
* Software:         
    * Arduino IDE
    * Salesforce:
         * Scheduled triggered flow
         * Named credential
         * External services to Thingspeak (Open API Definitions)
         * Custom Object: Sensor

##  Hardware
![Schematics](https://raw.githubusercontent.com/krukmat/AlarmForce-Demo/master/images/AlarmForce%20-%20Schematics.png)
![Schematics](https://raw.githubusercontent.com/krukmat/AlarmForce-Demo/master/images/Hardware.png)

## General Schema
![Schematics](https://raw.githubusercontent.com/krukmat/AlarmForce-Demo/master/Untitled%20Diagram.png)

## Salesforce: 
![Schematics](https://raw.githubusercontent.com/krukmat/AlarmForce-Demo/master/images/Salesforce.png)
![Schematics](https://raw.githubusercontent.com/krukmat/AlarmForce-Demo/master/images/flow.png)

