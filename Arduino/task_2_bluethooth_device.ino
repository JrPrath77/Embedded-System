void setup() 
{
    Serial.begin(9600);
    Serial.println("Serial echo Test"); // Changed Serial.write to Serial.println for better formatting
}

void loop() 
{
    if (Serial.available()) 
    {
        char enter_val = Serial.read(); // Moved variable declaration inside the loop for readability and scope limitation
        
        switch (enter_val)
        {
            case 'a':
                Serial.println("apple"); // Changed Serial.write to Serial.println for better formatting
                break;
            case 'b':
                Serial.println("ball");
                break;
            case 'c':
                Serial.println("cat");
                break;
            case 'd':
                Serial.println("dog");
                break;
            case '1':
                Serial.println("one");
                break;
            case '2':
                Serial.println("two");
                break;
            case '3':
                Serial.println("three"); // Changed "Three" to "three" for consistency
                break;
            case '4':
                Serial.println("four"); // Changed "Four" to "four" for consistency
                break;
            default:
                Serial.println("Invalid input: " + String(enter_val)); // Improved output message to include the invalid input value
                break;
        }
    }
}
