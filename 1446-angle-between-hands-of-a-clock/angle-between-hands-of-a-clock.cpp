class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Convert hour to 12-hour format
        hour = hour % 12;
        
        // Calculate angle of minute hand from 12 o'clock
        double minuteAngle = minutes * 6.0;  // 6 degrees per minute
        
        // Calculate angle of hour hand from 12 o'clock
        // Hour hand moves 0.5 degrees per minute
        double hourAngle = (hour * 30.0) + (minutes * 0.5);  // 30 degrees per hour + 0.5 per minute
        
        // Calculate the absolute difference
        double diff = abs(hourAngle - minuteAngle);
        
        // Return the smaller angle (either diff or 360 - diff)
        return min(diff, 360.0 - diff);
    }
};
