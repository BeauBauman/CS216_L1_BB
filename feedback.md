**NG 7/2/2026**


* To provide you with thorough feedback, your instructor reads your code line by line, sometimes multiple times. Jumping from file to file is too time-consuming. Unless noted otherwise, place your class definitions above the main() and all function definitions below main(), all in one file. While the industry standard involves multi-source file programs, we will use a single file format for these labs unless instructed otherwise.


*  **feedback.md is for instructor use only.  Please DO NOT change the feedback.md**; make a copy if needed; do no add anything


* if any, items with (-X) - no deductions this time, serve as a warning; please ensure these errors are corrected, as repeating them in future assignments will result in X points being deducted


* in feedback, #N means line number, e.g.,


```text


* #25  global var(s); only constant may be global -10


meaning: see line #25 ; -10 deduction points for the mistake


```


* readability, comments; do not state the obvious, do not reiterate/duplicate the code,  AI and the textbooks reiterate/duplicate the code because they try to teach something, as a way of explanation; remove outdated code- it is disrespectful to leave outdated/commented out code; comments are supposed to help understand the code and not create unnecessary clutter; comments should be to the right of the statement whenever possible, not above => those who need to read them – will find them and read, those who do not will go to the next line; "Code never lies, comments sometimes do." - Ron Jeffries”; every C++ programmer knows how const, structs, function prototype looks like; what’s is the goal of excessive ____ and ****? what is the purpose of the comments as this(ese) one(s)? -2


```text


void sort_array(int arr[], int count) { // Implements bubble sort, descending order


  while (swapped) {


       


        swapped = false; // Default if not set to true, ends loop.


```


* no function prototypes -10


* function definition(s) above main() -5


* #13 what for?


* may not use range-based loops -2


* poor Id(s)  and/or inconsistent naming convention; ids should be self-documenting and as short as possible; use verbs for functions and nouns for variables; use camel-casing for variables (errorMessage) enum & const should be in upper case with words separated by “_”, e.g., MAX_TERMS, PRINT_RECORDS; pointer variables should start with p( if single)  or pp( if double pointer); flags isValid ( clearly what true would mean); if copying – e.g rhsQueue or scrQueue ( rhs- right-hand side, src – source); do not use IDs and default values that are same as or very similar to C++  keywords and functions; no need to call an array “array”- it is obvious; vars should not be called value;  one char identifiers (e.g. j,k, i) are only suitable for loop counters;  -2


```text


char c


sort_array


int arr[]


void read_array(string arr[], int count){


    for (int i = 0; i < count; i++) {


        cout << arr[i] << endl;


    }


}


```


* #62  and like: what for? please only implement features per the assignment description; do not add any other features or options; do not use something that has not been covered in class (-5)


* missing feedback.md -5


* uses one or more of the following: non-allowed libraries, break (Ok in switch), return( empty or non-empty, e.g., return 0;, return;) or exit() in loops and ifs, go to or continue, empty return (e.g., return;), infinite loops (while(true) or similar), void function with a return statement; multiple return statements in a non-recursive function;  there is no situation where same effect cannot be achieved by a logical statement; in other words, there is no situation in this realm that cannot be described by using a combination of relational, comparison, and logical operators; you can always  write a loop condition to exit naturally when needed; see the syllabus and HW #3 –   stopped grading
