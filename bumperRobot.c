/**
 * Buster...
 *  ______                                                
 * |_   _ \                                               
 *   | |_) | __   _   _ .--..--.  _ .--.   .---.  _ .--.  
 *   |  __'.[  | | | [ `.-. .-. |[ '/'`\ \/ /__\\[ `/'`\] 
 *  _| |__) || \_/ |, | | | | | | | \__/ || \__., | |     
 * |_______/ '.__.'_/[___||__||__]| ;.__/  '.__.'[___]    
 * |_   __ \         [  |        [__|  / |_               
 *   | |__) |   .--.  | |.--.    .--. `| |-'              
 *   |  __ /  / .'`\ \| '/'`\ \/ .'`\ \| |                
 *  _| |  \ \_| \__. ||  \__/ || \__. || |,               
 * |____| |___|'.__.'[__;.__.'  '.__.' \__/
 * 
 *  > by Nathan
 *  > for Mr. Williams
 *  > TEJ3M0
 */

/* Pins for the LEDs (d for diode) */
const int d1 = 12;
const int d2 = 13;
/* Pins for the switches */
const int s1 = 6;
const int s2 = 5;
/* Pins for the left motor */
const int l1 = 10;
const int l2 = 11;
/* Pins for the right motor */
const int r1 = 8;
const int r2 = 9;

// setup() - setup the robot
void setup()
{
    // Set Serial Baud Rate
    Serial.begin(9600);

    // Set all pins to be either an input or output
    Serial.print("Setting up pins...\n\n");
    pinMode(d1, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(s1, INPUT);
    pinMode(s2, INPUT);
    pinMode(l1, OUTPUT);
    pinMode(l2, OUTPUT);
    pinMode(r1, OUTPUT);
    pinMode(r2, OUTPUT);

    Serial.print("Starting...\n\n\n");
    digitalWrite(d1, HIGH);
    digitalWrite(d2, HIGH);
    delay(100);
    Serial.print("    ____             __           \n");
    digitalWrite(d1, LOW);
    digitalWrite(d2, LOW);
    delay(100);
    Serial.print("   / __ )__  _______/ /____  _____\n");
    digitalWrite(d1, HIGH);
    digitalWrite(d2, HIGH);
    delay(100);
    Serial.print("  / __  / / / / ___/ __/ _ \\/ ___/\n");
    digitalWrite(d1, LOW);
    digitalWrite(d2, LOW);
    delay(100);
    Serial.print(" / /_/ / /_/ (__  ) /_/  __/ /    \n");
    digitalWrite(d1, HIGH);
    digitalWrite(d2, HIGH);
    delay(100);
    Serial.print("/_____/\\__,_/____/\\__/\\___/_/     \n\n");
    digitalWrite(d1, LOW);
    digitalWrite(d2, LOW);
    delay(100);
    Serial.print("   --> by Nathan\n\n");

    stop();
}

// loop() - keeps updating the "state" of the robot but detecting which bumpers are pressed
void loop()
{ // NOTE! There is a small "bias" where the robot would "prefer" to detect the first sensor first then make a decision based on that
    //     Hence, if BOTH switches are pressed, the robot could "prefer" to act the same as if only 's1' was pressed
    //     In the future, it would be ideal to introduce a method in which the robot

    // Detect if the switches have been pressed
    if (digitalRead(s1))
    {
        digitalWrite(d1, HIGH); // IF the right bumper is pressed
        turnLeft();             // THEN run 'turnLeft()' --> reverse then turn left
        digitalWrite(d1, LOW);
    }
    else if (digitalRead(s2))
    {
        digitalWrite(d2, HIGH); // IF the left bumper is pressed
        turnRight();            // THEN run 'turnRight()'
        digitalWrite(d2, LOW);
    }
    else
    {                // OTHERWISE (neither of the bumpers are pressed)
        goForward(); // THEN go forward
    }
}

// goForward() - go forward
void goForward()
{
    Serial.print("Going FORWARD\n");
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    delay(10); // a shorter delay makes the robot update faster but not go crazy updating the state of the motors
}

// reverse() - go backward
void reverse()
{
    Serial.print("Going BACKWARD\n");
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    delay(1000); // Delay for a second
}

// stop() - stop the robot
void stop()
{
    Serial.print("STOPPING...\n");
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
}

// turnLeft() - reverse than turn left
void turnLeft()
{
    reverse(); // reverse before turning left
    Serial.print("Turning LEFT\n");
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    delay(1000); // turn left for a second
}

// turnRight() - reverse than turn right
void turnRight()
{
    reverse(); // reverse before turning right
    Serial.print("Turning RIGHT\n");
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    delay(1000); // turn right for a second
}
