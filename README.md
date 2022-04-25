![alt text](https://github.com/moondisco/SensorsEvolve/blob/main/EVOLVE-Logo.png)
[![balena deploy button](https://www.balena.io/deploy.svg)](https://dashboard.balena-cloud.com/deploy?repoUrl=https://github.com/moondisco/SensorsEvolve>)

# EvolveSensors
Sensors with an Adafruit M0, Raspberry Pi 4, Docker, BalenaOS, Grafana, NGINX, PHPMyAdmin, WiFi HotSpot, and Apache
The Feather M0 is using AM2315 Sensors with a TCA9518A.

This code is written for a AdaFruit M0 WiFi Microcontroller and a Raspberry Pi 4/400/Zero WH/Zero WH 2.

The OS for the Raspberry Pi is BalenaOS. Download this config, then push it to balenacloud to use this with MySQL, PHP, NGINX, Apache, and Grafana.

Currently is this is configured to run with BalenaOS. This sends data to the Raspberry Pi via the WiFi.
The Pi must be connect to a router with Ethernet for this to work with BalenaCloud.
The Pi creates it's own hotspot that Adafruit's Feather M0 WiFi sends data to the MySQL database.

When the pi is being updated causing the Feather M0 to not beable to connect to the Pi, the M0 with enter a reset state.
It will try to connect every 10-15sec, when it fails it will reset, until it has established a connection.

Things working:
    -Currently the Admin username and password are "Admin" and "EvolveAdmin".

    -PHPMyAdmin login is "root" and "EvolveAdmin"

    -MySQL login is "root" and "EvolveAdmin" with the sub user for grafana "grafana" and "Evolve" to access "grafanadb".

    -Grafana login is "Admin" and "EvolveAdmin"

Setup for MySQL in Grafana is as follows:

    Host: 10.42.0.1:3306

    User: grafana

    Pass: Evolve

    Min Time interval: 10s
    
