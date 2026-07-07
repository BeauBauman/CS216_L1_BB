#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

const string INPUT_FILE_NAME = "input.txt";
const string OUTPUT_FILE_NAME = "output.txt";
const int MAX_ARR_SIZE = 1000; 

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

void print_stored_values(string arr[], int true_count) {
    cout << "Stored values:" << endl;
    read_array(arr, true_count);
    int integer_array[MAX_ARR_SIZE];
    string_array_to_int(arr, true_count, integer_array); // New array of the same vals, but size is equal to data and contains only int
    int val_sum = get_array_sum(integer_array, true_count);
    cout << left << setw(15) << "Statistic"
     << right << setw(10) << "Value"
     << endl;

    cout << left << setw(15) << "Sum"
         << right << setw(10) << fixed << setprecision(2) << static_cast<double>(val_sum)
         << endl;
    
    cout << left << setw(15) << "Median"
         << right << setw(10) << fixed << setprecision(2) << get_median(integer_array, true_count)
         << endl;
    cout << left << setw(15) << "Mean"
         << right << setw(10) << fixed << setprecision(2) << (static_cast<double>(val_sum) / true_count)
         << endl;
    return;
}

void print_sorted_values(string arr[], int true_count){
    int integer_array[MAX_ARR_SIZE];
    string_array_to_int(arr, true_count, integer_array);
    sort_array(integer_array, true_count);
    read_array(integer_array, true_count);
    return;
}

void write_array_to_file(int arr[], int count, ofstream &output_file) { // Avoid opening the same file twice
    for (int i = 0; i < count; i++) {
        output_file << arr[i] << endl;
    }
}

void save_data(string arr[], int true_count){
    int integer_array[MAX_ARR_SIZE];
    string_array_to_int(arr, true_count, integer_array);
    sort_array(integer_array, true_count);
    
    ofstream output_file(OUTPUT_FILE_NAME);
    output_file << "Sorted array: " << endl;
    write_array_to_file(integer_array, true_count, output_file);
    int sum = get_array_sum(integer_array, true_count);
    
    output_file << left << setw(15) << "Statistic"
     << right << setw(10) << "Value"
     << endl;

    output_file << left << setw(15) << "Sum"
         << right << setw(10) << fixed << setprecision(2) << static_cast<double>(sum)
         << endl;
    
    output_file << left << setw(15) << "Median"
         << right << setw(10) << fixed << setprecision(2) << get_median(integer_array, true_count)
         << endl;
    output_file << left << setw(15) << "Mean"
         << right << setw(10) << fixed << setprecision(2) << (static_cast<double>(sum) / true_count)
         << endl;
    
    return;
}

int main()
{
    bool end = false;
    string arr[MAX_ARR_SIZE];
    int true_count = get_data(arr, MAX_ARR_SIZE); // Number of actual values in the array
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
                    print_stored_values(arr, true_count);
                    break;
                case 2:
                    print_sorted_values(arr, true_count);
                    break;
                case 3:
                    save_data(arr, true_count);
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
/* Please select an option:
1 - Print stored values alongside mean, sum, and median.
2 - Print sorted values in descending order.
3 - Save data and stats to output file, then quit.
hello
Invalid input
Please select an option:
1 - Print stored values alongside mean, sum, and median.
2 - Print sorted values in descending order.
3 - Save data and stats to output file, then quit.
1
Stored values:
123
456
65
55
Statistic           Value
Sum                699.00
Median              94.00
Mean               174.75
Please select an option:
1 - Print stored values alongside mean, sum, and median.
2 - Print sorted values in descending order.
3 - Save data and stats to output file, then quit.
2
456
123
65
55
Please select an option:
1 - Print stored values alongside mean, sum, and median.
2 - Print sorted values in descending order.
3 - Save data and stats to output file, then quit.
4
Invalid input
Please select an option:
1 - Print stored values alongside mean, sum, and median.
2 - Print sorted values in descending order.
3 - Save data and stats to output file, then quit.
3 */
