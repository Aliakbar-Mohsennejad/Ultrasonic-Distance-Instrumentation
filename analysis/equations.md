# Measurement Equations

**Time of Flight (ToF)**  
Distance is computed from the travel time of the ultrasonic pulse:
\[ D = \frac{t \times v}{2} \]
where *t* is the echo pulse duration and *v* is the speed of sound.

**Speed of Sound Compensation (Temperature & Humidity)**  
An empirical approximation used in this project:
\[ v(\text{m/s}) \approx 331.4 + 0.6T + 0.0124H \]
where *T* is temperature in °C and *H* is relative humidity in %.
