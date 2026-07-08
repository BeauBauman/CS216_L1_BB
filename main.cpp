#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

const string INPUT_FILE_NAME = "input.txt";
const string OUTPUT_FILE_NAME = "output.txt";
const int MAX_ARR_SIZE = 1000; // 

// Realized there was a cleaner solution, therefore unused. Left for later reference, ignore.
// Previously was using getline
int split_array_of_strings(string arr[], char delimiter, int count, int maxsize = 1000) {
    // Count is the # of valid entries in input array, maxsize is its maximum size
    string new_array[maxsize];
    string temp = "";
    int new_array_index = 0;
    for (int i = 0; i < count; i++) { // Iterate over each entry of the input array
        
        for (char c : arr[i]) { // Iterate over each character of each entry
            if (c == delimiter && temp != ""){ // When delimiter is hit, write to array and clear string
                new_array[new_array_index] = temp;
                new_array_index++;
                temp = "";
            } else {
                temp += c; // Write to temp until delimiter hit to split string
            }
        }
        new_array[new_array_index] = temp; // Get last value without needing delimiter
        temp = "";
    }
    if (new_array_index > maxsize) {
        cout << "Too many numbers, maxsize is " << maxsize; // Array too small
    } else {
        for (int i = 0; i < new_array_index; i++){
            arr[i] = new_array[i]; // Once done splitting, overwrite the original array
        }
    }
    return new_array_index; // New count of valid numbers in array
    
}

void sort_array(int arr[], int count) { // Implements bubble sort, descending order
    bool swapped = true;
    while (swapped) { 
        
        swapped = false; // Default if not set to true, ends loop.
        for (int i = 0; i < count-1; i++) {
            int temp = 0;
            if (arr[i] < arr[i+1]){
                temp = arr[i+1]; // Swap values
                arr[i+1] = arr[i];
                arr[i] = temp;
                swapped = true;
            }
        }
        
    }

}

void string_array_to_int(string arr[], int count, int new_array[]) {
    for (int i = 0; i < count; i++) {
        new_array[i] = stoi(arr[i]);
    }
}

double get_median(int arr[], int count) {
    sort_array(arr, count);
    double median = 0;
    if (count % 2 != 1) {
        median = (arr[(count-1)/2] + arr[(count+1)/2])/2.0; // Get avg of both sides if even length
    } else {
        median = arr[count/2];
    }
    return median;
}

void read_array(string arr[], int count){
    for (int i = 0; i < count; i++) {
        cout << arr[i] << endl;
    }
}

void read_array(int arr[], int count){ // Overloaded for ease of testing
    for (int i = 0; i < count; i++) {
        cout << arr[i] << endl;
    }
}

int get_array_sum(int arr[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }
    return sum;
}

int get_data(string arr[], int count) {
    string temp_text = ""; // Written to by getline, will contain the content of that line
    ifstream input_file(INPUT_FILE_NAME);
    if (!input_file) {
        cout << "File not found" << endl;
        return 0; // Not an exit code, 0 values loaded.
    }
    int i = 0; // Iteration variable for while loop
    while (input_file >> temp_text) {
        
        if (i >= count){
            cout << "Too many numbers, max is " << count << endl;
            break;
        }
        arr[i] = temp_text;
        i++;
        
    }
    input_file.close();
    return i; // Number of actual values in the array
}

void output_stats(ostream &output, int arr[], int fives[], int sevens[],
                        int neither[], int count, int &count_fives, int &count_sevens, 
                        int &count_neither) { // Allows reusable formatting for cout and file writing
    output << left << setw(20) << "Category"
         << right << setw(15) << "Values"
         << endl;
    
    output << left << setw(20) << "Divisible by 5" << endl;
    for (int i = 0; i < count_fives; i++)
    {
        output << right << setw(35) << fives[i] << endl;
    }
    
    output << left << setw(20) << "Divisible by 7" << endl;
    for (int i = 0; i < count_sevens; i++)
    {
        output << right << setw(35) << sevens[i] << endl;
    }
    
    output << left << setw(20) << "Neither" << endl;
    for (int i = 0; i < count_neither; i++)
    {
        output << right << setw(35) << neither[i] << endl;
    }
    
    
    // Statistics table
    
    int sum_fives = static_cast<double>(get_array_sum(fives, count_fives));
    int sum_sevens = static_cast<double>(get_array_sum(sevens, count_sevens));
    int sum_neither = static_cast<double>(get_array_sum(neither, count_neither));
    
    if (count_fives < 1) {
        mean_fives = 0;
    } else {
       int mean_fives = (static_cast<double>(get_array_sum(fives, count_fives)) / count_fives); 
    }
    if (count_sevens < 1) {
        mean_sevens = 0;
    } else {
        int mean_sevens = (static_cast<double>(get_array_sum(sevens, count_sevens)) / count_sevens);
    }
    if (count_neither < 1) {
        mean_neither = 0;
    } else {
        int mean_neither = (static_cast<double>(get_array_sum(neither, count_neither)) / count_neither);
    }
    
    int median_fives = get_median(fives, count_fives);
    int median_sevens = get_median(sevens, count_sevens);
    int median_neither = get_median(neither, count_neither);
    
    output << endl;
    
    output << left << setw(20) << "Category"
         << right << setw(15) << "Sum"
         << right << setw(15) << "Mean"
         << right << setw(15) << "Median"
         << endl;
    
    output << left << setw(20) << "Divisible by 5"
         << right << setw(15) << sum_fives
         << right << setw(15) << mean_fives
         << right << setw(15) << median_fives
         << endl;
    
    output << left << setw(20) << "Divisible by 7"
         << right << setw(15) << sum_sevens
         << right << setw(15) << mean_sevens
         << right << setw(15) << median_sevens
         << endl;
    
    output << left << setw(20) << "Neither"
         << right << setw(15) << sum_neither
         << right << setw(15) << mean_neither
         << right << setw(15) << median_neither
         << endl;
}

void print_stored_values(int arr[], int fives[], int sevens[],
                        int neither[], int count, int &count_fives, int &count_sevens, 
                        int &count_neither) {
    cout << "Stored values:" << endl;
    output_stats(cout, arr, fives, sevens, neither, count, count_fives, count_sevens, count_neither);
    return;
}

void print_sorted_values(int arr[], int fives[], int sevens[],
                        int neither[], int count, int &count_fives, int &count_sevens, 
                        int &count_neither){
    sort_array(fives, count_fives);
    cout << "Fives: " << endl; 
    read_array(fives, count_fives);
    
    sort_array(sevens, count_sevens);
    cout << "Sevens: " << endl; 
    read_array(sevens, count_sevens);
    
    sort_array(neither, count_neither);
    cout << "Neither: " << endl; 
    read_array(neither, count_neither);
    return;
}

void separate_by_divisor(int arr[], int fives[], int sevens[],
                        int neither[], int count, int &count_fives, int &count_sevens, 
                        int &count_neither) { // Removes all numbers from input divisible by number, adds to new array
    count_fives = 0;
    count_sevens = 0;
    count_neither = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] % 5 == 0) {
            fives[count_fives] = arr[i];
            count_fives++;
        }
        else if (arr[i] % 7 == 0) {
            sevens[count_sevens] = arr[i];
            count_sevens++;
        }
        else {
            neither[count_neither] = arr[i];
            count_neither++;
        }
    }
    

    
    
}

void write_array_to_file(int arr[], int count, ofstream &output_file) { // Avoid opening the same file twice
    for (int i = 0; i < count; i++) {
        output_file << arr[i] << endl;
    }
}

void save_data(int arr[], int fives[], int sevens[],
                        int neither[], int count, int &count_fives, int &count_sevens, 
                        int &count_neither){
    
    sort_array(fives, count_fives);
    sort_array(sevens, count_sevens);
    sort_array(neither, count_neither);
    
    ofstream output_file(OUTPUT_FILE_NAME);
    output_stats(output_file, arr, fives, sevens, neither, count, count_fives, count_sevens, count_neither);
    
    return;
}

int main()
{
    bool end = false;
    string arr[MAX_ARR_SIZE];
    int true_count = get_data(arr, MAX_ARR_SIZE); // Number of actual values in the array
    int integers[MAX_ARR_SIZE];
    string_array_to_int(arr, true_count, integers);
    int fives[MAX_ARR_SIZE];
    int sevens[MAX_ARR_SIZE];
    int neither[MAX_ARR_SIZE];
    int count_fives = 0;
    int count_sevens = 0;
    int count_neither = 0;
    separate_by_divisor(integers, fives, sevens, neither, true_count, count_fives, count_sevens, count_neither);
    if (true_count == 0) {
        end = true; // Program cannot continue
        cout << "No data loaded.";
    }
    while (!end){ // Main loop
    
        // Prompt and recieve menu choice
        int menu_choice;
        cout << "Please select an option:\n1 - Print stored values alongside mean, sum, and median.\n2 - Print sorted values in descending order.\n3 - Save data and stats to output file, then quit." << endl;
        if (!(cin >> menu_choice)) { // Handle failed input
            cin.clear();
            cin.ignore(1000, '\n'); // Ignore invalid input & flush input buffer
            cout << "Invalid input" << endl;
            continue;
        } else {
        
            switch (menu_choice){
                // Print values and stats
                case 1:
                    // Define variables
                    print_stored_values(integers, fives, sevens, neither, true_count, count_fives, count_sevens, count_neither);
                    break;
                case 2:
                    print_sorted_values(integers, fives, sevens, neither, true_count, count_fives, count_sevens, count_neither);
                    break;
                case 3:
                    save_data(integers, fives, sevens, neither, true_count, count_fives, count_sevens, count_neither);
                    end = true;
                    break;
                default:
                    cout << "Invalid input" << endl;
                    break;
        }
                
    }}

    return 0;
}

// Sample output
/*Please select an option:
1 - Print stored values alongside mean, sum, and median.
2 - Print sorted values in descending order.
3 - Save data and stats to output file, then quit.
1
Stored values:
Category                     Values
Divisible by 5      
                                 35
                                345
Divisible by 7      
                                532
Neither             
                               3324
                                 23
                                 67
                                 23
                                 67
                                212

Category                        Sum           Mean         Median
Divisible by 5                  380            190            190
Divisible by 7                  532            532            532
Neither                        3716            619             67
Please select an option:
1 - Print stored values alongside mean, sum, and median.
2 - Print sorted values in descending order.
3 - Save data and stats to output file, then quit.
2
Fives: 
345
35
Sevens: 
532
Neither: 
3324
212
67
67
23
23
Please select an option:
1 - Print stored values alongside mean, sum, and median.
2 - Print sorted values in descending order.
3 - Save data and stats to output file, then quit.
3 */
