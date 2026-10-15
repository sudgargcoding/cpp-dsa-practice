class Solution {
    public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int numberOfDays = temperatures.size();
        std::vector<int> daysToWait(numberOfDays, 0);
        std::stack<int> indicesOfColderDays;
        for (int currentDayIndex = 0; currentDayIndex < numberOfDays; ++currentDayIndex) {
            // While there are colder days recorded and the current day is warmer than the top colder day.
            while (!indicesOfColderDays.empty() && temperatures[currentDayIndex] > temperatures[indicesOfColderDays.top()]) {
                int colderDayIndex = indicesOfColderDays.top();
                indicesOfColderDays.pop();
                // Calculate the number of days to wait for a warmer temperature.
                daysToWait[colderDayIndex] = currentDayIndex - colderDayIndex;
            }
            // Push the current day's index onto the stack for future comparisons.
            indicesOfColderDays.push(currentDayIndex);
        }
        // Any remaining indices in the stack represent days for which no warmer day was found.
        return daysToWait;
    }
};