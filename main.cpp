#include <iostream>
#include <random>

using namespace std;

string randomStrGen(int length) {
    static string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string result;
    for (int i = 0; i < length; i++)
        result += charset[rand() % charset.length()];
    return result;
}

int main() {
    freopen("../output3.txt", "w", stdout);
    srand(time(nullptr));
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> fileAmount(1100, 1200); // define file amount
    int files = fileAmount(gen);
    uniform_int_distribution<> passwordRange(50, 90); // define range, to put password
    uniform_int_distribution<> textLength(5, 30); // define text len
    int num = passwordRange(gen);
    for (int i = 0; i <= files; i++) {
        if (i == num) {
            cout << "echo \"password: alohmora\" > file" << i << "; chmod 000 file" << i
                 << "; "; // вы можете задать свой пароль
        } else {
            cout << "echo \"" << randomStrGen(textLength(gen)) << "\" > file" << i << "; ";
            if (rand() % 28 == 0) {
                // no access to the file
                cout << "chmod 000 file" << i << "; ";
            }
        }
    }
}