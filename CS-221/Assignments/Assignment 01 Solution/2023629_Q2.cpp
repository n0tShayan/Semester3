#include <iostream>
using namespace std;

struct UniverseCoordinate {
    int s_number, x_position, y_position;
    bool is_snake;
};

// Function to create a 2D dynamic array
UniverseCoordinate** createarray(int rows, int cols) {
    UniverseCoordinate** arr = new UniverseCoordinate*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new UniverseCoordinate[cols];
    }
    return arr;
}

// Function to expand an existing dynamic array
UniverseCoordinate** expandarray(UniverseCoordinate** oldarr, int new_rows, int new_cols, int old_rows, int old_cols) {
    // Create new array with expanded dimensions
    UniverseCoordinate** newarr = createarray(new_rows, new_cols);

    // Copy the contents of the old array into the new one
    for (int i = 0; i < old_rows; i++) {
        for (int j = 0; j < old_cols; j++) {
            newarr[i][j] = oldarr[i][j];
        }
    }

    // Initialize the newly added cells
    for (int i = old_rows; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            newarr[i][j].s_number = 0;
            newarr[i][j].x_position = j + 1;
            newarr[i][j].y_position = i + 1;
            newarr[i][j].is_snake = false;
        }
    }
    for (int i = 0; i < old_rows; i++) {
        for (int j = old_cols; j < new_cols; j++) {
            newarr[i][j].s_number = 0;
            newarr[i][j].x_position = j + 1;
            newarr[i][j].y_position = i + 1;
            newarr[i][j].is_snake = false;
        }
    }

    // Deallocate old array
    for (int i = 0; i < old_rows; i++) {
        delete[] oldarr[i];
    }
    delete[] oldarr;

    return newarr;
}

// Function to print the 2D array
void printUniverse(UniverseCoordinate** arr, int rows, int cols) {
    cout << "\nCurrent Universe Data:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j].is_snake) {
                cout << "Snake#" << arr[i][j].s_number << " ";
            } else {
                cout << "Empty ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int rows, cols;
    int totalsnakes = 0;
    int sxcord, sycord;

    cout << "Hey Scientist, Enter the Rows and Columns for the Universe Data:" << endl;
    cin >> rows >> cols;

    // Create the initial UniverseData array
    UniverseCoordinate** arr = createarray(rows, cols);

    // Initialize the array with no snakes
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j].s_number = 0;
            arr[i][j].x_position = j + 1;
            arr[i][j].y_position = i + 1;
            arr[i][j].is_snake = false;
        }
    }

    // Add snakes to the universe
    cout << "Enter the number of snakes in the Universe: ";
    cin >> totalsnakes;

    for (int i = 0; i < totalsnakes; i++) {
        cout << "Enter the X & Y coordinates for Snake " << i + 1 << " (0-indexed):" << endl;
        cin >> sxcord >> sycord;

        if (sxcord >= 0 && sxcord < rows && sycord >= 0 && sycord < cols) {
            if (arr[sxcord][sycord].is_snake) {
                cout << "Snake already present at (" << sxcord << ", " << sycord << "). Skipping." << endl;
            } else {
                arr[sxcord][sycord].s_number = i + 1;
                arr[sxcord][sycord].is_snake = true;
            }
        } else {
            cout << "Invalid coordinates, skipping this snake." << endl;
        }
    }

    // Print the current state of the universe
    printUniverse(arr, rows, cols);

    // Ask the user if they want to expand the area
    char choice;
    int nrows, ncols;
    cout << "Do you want to expand the AREA? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "Enter the new number of Rows and Columns for UniverseData:" << endl;
        cin >> nrows >> ncols;

        // Expand the array and assign it to arr
        arr = expandarray(arr, nrows, ncols, rows, cols);

        // Update the dimensions
        rows = nrows;
        cols = ncols;

        // Ask for new snakes in the expanded area
        cout << "Enter the number of new snakes for the expanded Universe: ";
        cin >> totalsnakes;

        for (int i = 0; i < totalsnakes; i++) {
            cout << "Enter the X & Y coordinates for new Snake " << i + 1 << " (0-indexed):" << endl;
            cin >> sxcord >> sycord;

            if (sxcord >= 0 && sxcord < rows && sycord >= 0 && sycord < cols) {
                if (arr[sxcord][sycord].is_snake) {
                    cout << "Snake already present at (" << sxcord << ", " << sycord << "). Skipping." << endl;
                } else {
                    arr[sxcord][sycord].s_number = i + 1;
                    arr[sxcord][sycord].is_snake = true;
                }
            } else {
                cout << "Invalid coordinates, skipping this snake." << endl;
            }
        }

        // Print the expanded universe
        printUniverse(arr, rows, cols);
    } else {
        cout << "No expansion chosen." << endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
