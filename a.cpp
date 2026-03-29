/**
 * @file    a.cpp
 * @brief   Seven-Segment Time Display — Terminal-based date/time renderer
 *
 * This program retrieves the current local date and time from the system clock
 * and renders it to the terminal using ASCII art that mimics a classic
 * seven-segment LED display. Each digit (0–9) and separator character
 * (':', '-', '/', ' ') is mapped to a 3×3 character grid, and three output
 * lines are composed to produce the final display.
 *
 * Supported characters:
 *   Digits  : 0 1 2 3 4 5 6 7 8 9
 *   Colon   : ':'  (time separator)
 *   Dash    : '-'  (date-time separator)
 *   Slash   : '/'  (date separator)
 *   Space   : ' '  (blank segment)
 *
 * Error codes returned by display():
 *   P_OK        ( 0)  — Success
 *   P_ERR_RANGE (-5)  — Input string length out of valid range
 *   P_ERR_VAL   (-10) — Input contains unsupported characters
 *
 * Build:
 *   g++ -o seven_seg a.cpp
 *
 * Usage:
 *   ./seven_seg
 *
 * @author  AD Digital Labs
 * @see     https://github.com/ad-digital-labs/Seven_segment-time_display
 */

/* ─── Preprocessor Macros: Error / Status Codes ─────────────────────────── */

#define P_OK 0            /**< Success — no errors detected.                  */
#define P_ERR_RANGE -5    /**< Range error — input string too short or too long. */
#define P_ERR_VAL -10     /**< Value error — input contains invalid characters.  */


/* ─── Standard Library Includes ──────────────────────────────────────────── */

#include <iostream>       // std::cout, std::endl — console output
#include <cctype>         // std::isdigit       — character classification
#include <locale>         // Locale-related utilities (included for portability)
#include <string>         // std::string, std::to_string — string handling
#include <time.h>         // time(), localtime(), struct tm — system clock access


using namespace std;      // Import standard namespace for convenience


/**
 * @brief Segment lookup table — ASCII art patterns for each displayable character.
 *
 * Each entry is a 9-character string encoding a 3×3 grid:
 *   Positions 0–2 → top row,  3–5 → middle row,  6–8 → bottom row.
 *
 * Index mapping:
 *   0–9  : digits '0' through '9'
 *   10   : colon  ':'  (time separator)
 *   11   : dash   '-'  (date-time separator)
 *   12   : slash  '/'  (date separator)
 *   13   : space  ' '  (blank segment)
 */
std::string segment[14]
{
    " _ | ||_|",       // 0  — digit zero
    "     |  |",       // 1  — digit one
    " _  _||_ ",       // 2  — digit two
    " _  _| _|",       // 3  — digit three
    "   |_|  |",       // 4  — digit four
    " _ |_  _|",       // 5  — digit five
    "   |_ |_|",       // 6  — digit six
    " _   |  |",       // 7  — digit seven
    " _ |_||_|",       // 8  — digit eight
    " _ |_|  |",       // 9  — digit nine
    "    *  * ",       // 10 — colon ':'
    "      ***",       // 11 — dash  '-'
    "     * * ",       // 12 — slash '/'
    "         "        // 13 — space ' '

};

/**
 * @brief   Render a string of digits and separators as seven-segment ASCII art.
 *
 * Iterates over each character in @p str, maps it to its segment pattern, and
 * builds three output lines (top, middle, bottom) that are printed to stdout.
 *
 * @param   str   The formatted date/time string to display.
 * @return  P_OK on success, P_ERR_RANGE if the string length is invalid,
 *          or P_ERR_VAL if any character is unsupported.
 */
int display(std::string str)
{

    int res;                    // Function return code (P_OK, P_ERR_RANGE, or P_ERR_VAL)
    int tcount;                 // Counter for invalid (unsupported) characters

    int i;                      // Loop index — current character position in str
    int j;                      // (unused — reserved for future use)
    int k;                      // Inner loop index — column within the 3×3 segment grid

    int x;                      // Resolved segment index for the current character

    std::string ln01="";        // Accumulator for the top row of segment output
    std::string ln02="";        // Accumulator for the middle row of segment output
    std::string ln03="";        // Accumulator for the bottom row of segment output

    // Validate input length: must be between 2 and 19 characters (inclusive)
    if(str.length()>1 && str.length()<20)
    {
        tcount=0;               // Reset invalid-character counter



        // Iterate over each character and map it to a segment index
        for(i=0; i<str.length(); i++)
        {
            // Check if the character is a supported digit or separator
            if( std::isdigit(str[i])==true || str[i]==':' || str[i]=='-' || str[i]=='/' || str[i]==' ')
            {

                if(isdigit(str[i])==true)
                {
                    x=str[i]-'0';           // Convert ASCII digit to integer (0–9)

                }else if(str[i]==':')
                {
                    x=10;                   // Map colon to segment index 10
                }else if(str[i]=='-')
                {
                    x=11;                   // Map dash to segment index 11

                }else if(str[i]=='/')
                {
                    x=12;                   // Map slash to segment index 12

                }else if(str[i]==' ')
                {
                    x=13;                   // Map space to segment index 13

                };


                // Extract the 3 columns of the segment pattern into the output lines
                k=0;
                while(k<3)
                {
                    ln01+=segment[ x ][k];      // Top row character
                    ln02+=segment[ x ][k+3];    // Middle row character
                    ln03+=segment[ x ][k+6];    // Bottom row character

                    k++;
                };


            }else
            {
                tcount++;               // Increment invalid-character counter

            };

            // Append a space after each character for visual separation
            ln01+=" ";
            ln02+=" ";
            ln03+=" ";


        };



        // If all characters were valid, print the three-line display
        if(tcount==0)
        {
            cout<<ln01<<std::endl;      // Print top row
            cout<<ln02<<std::endl;      // Print middle row
            cout<<ln03<<std::endl;      // Print bottom row

            res=P_OK;                   // Signal success

        }else
        {
            res=P_ERR_VAL;              // Signal invalid-character error

        };


    }else
    {
        res=P_ERR_RANGE;                // Signal out-of-range error
    };

    return res;                         // Return status code to caller

};



/**
 * @brief   Build a formatted date/time string from the system clock and display it.
 *
 * Retrieves the current local time via localtime(), formats it as
 * "MM/DD/YYYY -HH:MM", and passes the result to display() for rendering.
 *
 * @return  The status code returned by display().
 */
int display_time()
{
    int res;                    // Return code propagated from display()

    int h;                      // Current hour   (0–23)
    int u;                      // Current minute  (0–59)
    int m;                      // Current month   (0–11 from struct tm)
    int d;                      // Current day of the month (1–31)
    int y;                      // Current year    (full four-digit year)

    std::string str01="";       // Accumulator for the formatted date/time string

    time_t tm01;                // Raw calendar time value (seconds since epoch)
    tm *ctm01;                  // Pointer to broken-down local time structure

    tm01=time(NULL);                 // Obtain the current calendar time
    ctm01=localtime(&tm01);          // Convert to local broken-down time

    // Extract individual time components from the tm structure
    h=ctm01->tm_hour;                // Hour   (0–23)
    u=ctm01->tm_min;                 // Minute (0–59)
    m=ctm01->tm_mon;                 // Month  (0–11, January = 0)
    d=ctm01->tm_mday;                // Day    (1–31)
    y=ctm01->tm_year+1900;           // Year   (tm_year is years since 1900)

    // Zero-pad month and append date separator
    if(m<10)
    {
        str01+="0";                  // Pad single-digit month with leading zero
    };

    str01+=to_string(m);             // Append month value
    str01+="/";                      // Append date separator

    // Zero-pad day, append day/year and date-time separator
    if(d<10)
    {
        str01+="0";                  // Pad single-digit day with leading zero
    };

    str01+=to_string(d) + "/" + to_string(y)+" -";  // "DD/YYYY -"

    // Zero-pad hour and append time separator
    if(h<10)
    {
        str01+="0";                  // Pad single-digit hour with leading zero
    };
    str01+=to_string(h)+":";         // Append hour and colon
    
    // Zero-pad minute
    if(u<10)
    {
        str01+="0";                  // Pad single-digit minute with leading zero
    };
    str01+=to_string(u);             // Append minute value


    res=display(str01);               // Render the formatted string as seven-segment art


    return res;                       // Propagate status code to caller


};




/**
 * @brief   Program entry point.
 *
 * Calls display_time() to render the current date and time, then inspects the
 * return code to print a human-readable error message if something went wrong.
 *
 * @param   argc  Argument count   (unused).
 * @param   argv  Argument vector  (unused).
 * @return  0 unconditionally.
 */
int main(int argc, char* argv[])
{

    int result;                      // Status code from display_time()

    cout<<endl<<endl;                // Print leading blank lines for spacing

    result=display_time();           // Build and render the seven-segment display

    // Handle and report any errors returned by display_time()
    if(result!=P_OK)
    {
        if(result==P_ERR_RANGE)
        {
            cout<<"ERROR: Date values out of range."<<endl;         // Length validation failed
        }else if(result==P_ERR_VAL)
        {
            cout<<"Error: Time variiables not in digits."<<endl;    // Invalid characters detected
        }else
        {
            cout<<"ERROR: Unexpected error occurred."<<endl;        // Catch-all for unknown errors
        };

    };

    cout<<endl<<endl;               // Print trailing blank lines for spacing


    return 0;                        // Exit with success status

};




