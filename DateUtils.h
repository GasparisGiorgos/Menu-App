#ifndef DATE_UTILS_H
#define DATE_UTILS_H

#include <string>
#include <ctime>

namespace DateUtils {
    // We use "inline" because the function definition is inside the header
    inline std::string getGreekDayOfWeek() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int dayOfWeek = ltm->tm_wday; 

        // 0 is Sunday, 1 is Monday...
        std::string days[] = {"Κυριακή", "Δευτέρα", "Τρίτη", "Τετάρτη", "Πέμπτη", "Παρασκευή", "Σάββατο"};
        return days[dayOfWeek];
    }

    inline int getCurrentSemesterWeek(int startYear, int startMonth, int startDay) {
        time_t now = time(0);
        tm startDate = {0};
        startDate.tm_year = startYear - 1900; 
        startDate.tm_mon = startMonth - 1;    
        startDate.tm_mday = startDay;
        
        time_t start = mktime(&startDate);
        double secondsDiff = difftime(now, start);
        int daysDiff = secondsDiff / (60 * 60 * 24);
        
        if (daysDiff < 0) return 1; 
        
        int weeksPassed = daysDiff / 7;
        return (weeksPassed % 4) + 1; // Loops 1, 2, 3, 4
    }
}

#endif // DATE_UTILS_H