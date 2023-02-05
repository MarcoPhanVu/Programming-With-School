#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 100;
int sum = 0;

// Common Funcs
bool isPrime(int num);
bool isSCP(int num);

// De bai
void inputArray(int a[], int &n);
void outputArray(int a[], int n);
void randomArray(int a[], int n);
void tongSoNguyenKoAmChiaHet3Va4(int a[], int n);
void trungBinhCongSoLe(int a[], int n);
void tongSCP(int a[], int n);
void amountOfPrimes(int a[], int n);
void quest15(int a[], int n);
vvvv

int main() {
    int a[MAX_SIZE] = {131, 169, 393, 133, 666, 760, 32};
    int n = 7;
    int choice;
    
    // EM TỰ SET MENU THEO YÊU CẦU CỦA THẦY VỚI CHỈNH LẠI TEXT NHA NAM, ANH LƯỜI VC =))))

    do {
        // cout << "-----Menu-----" << "\n";
        // cout << "1. Nhap mang 1 chieu" << "\n";
        // cout << "2. Xuat mang 1 chieu" << "\n";
        // cout << "3. Tao mang 1 chieu ngau nhien" << "\n";
        // cout << "4. Tong so nguyen khong am chia het cho 3 va 4" << "\n";
        // cout << "5. Trung bình cộng số lẻ" << "\n";
        // cout << "6. Tổng chính phương" << "\n";
        // cout << "7. lượng prime" << "\n";
        // cout << "8. Yes/no if every digits in a num mod 3 = 0 + that num odd" << "\n";
        // cout << "9. yes/no if all num = possitive odd" << "\n";
        // cout << "10. Trung binh cong cac so le" << "\n";
        // cout << "0. Thoat" << "\n";
        // cout << "--------------" << "\n";
        cout << "Ban chon: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                inputArray(a, n);
                break;
            case 2:
                outputArray(a, n);
                break;
            case 3:
                randomArray(a, n);
                break;
            case 4: //3
                tongSoNguyenKoAmChiaHet3Va4(a, n);
                cout << "Tong so nguyen khong am chia het cho 3 va 4 la: "<< sum << "\n";
                break;
            case 5: //6 Trung bình cộng lẻ
                cout << "Trung bình cộng số lẻ: ";
                trungBinhCongSoLe(a, n);
                break;
            case 6: //9 Tổng chính phương
                cout << "Tổng số chính phương là: ";
                tongSCP(a, n);
                break;
            case 7: //12 lượng số nguyên tố
                cout << "Số lượng số nguyên tố là: ";
                amountOfPrimes(a, n);
                break;
            case 8: //15 Yes/no if digits chia hết cho 3 and allDigits == odd
                // Hard AF
                cout << "Co phan tu nguyen co cac chu so vua le vua chia het cho 3: ";
                quest15(a, n);
                break;
            case 9: //18 yes/no if all num = possitive odd
                cout << "Tat ca phan tu trong mang la so duong le: ";
                isAllElePosOdd(a, n);
                break;
            default:
                cout << "Nhap sai, vui long nhap lai" << "\n";
        }
    } while (choice != 0);

    return 0;
}

void inputArray(int a[], int &n) {
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    cout << "Nhap cac phan tu cua mang: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void outputArray(int a[], int n) {
    cout << "Mang vua nhap la: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void randomArray(int a[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

void tongSoNguyenKoAmChiaHet3Va4(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0 && a[i] % 3 == 0 && a[i] % 4 == 0) {
            sum += a[i];
        }
    }
    cout << sum << "\n";
}

void trungBinhCongSoLe(int a[], int n) {
    int tempCount = 0;
    int tempSum = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i]%2 == 1) {
            tempSum += a[i];
            ++tempCount;
        }
    }
    
    double result = float(tempSum)/float(tempCount);
    
    cout << result << "\n";
}

void tongSCP(int a[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (isSCP(a[i])) {
            result += a[i];
        }
    }
    cout << result << "\n";
}

void amountOfPrimes(int a[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            ++result;
        }
    }
    cout << result << "\n";
}

bool isPrime(int num) { //Function to check if prime
    if (num == 1 || num == 0) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

bool isSCP(int num) { // Check Số Chính Phương
    if (sqrt(num) == int(sqrt(num))) return true;
    return false;
}

void quest15(int a[], int n) { //All digit odds and %3 == 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) { //num isOdd 
            int tempNum = a[i];
            int tempDigit = 0;
            bool state = true;
            
            while (tempNum >= 1) { //extract digit
                tempDigit = tempNum%10;
                tempNum /= 10;
                if (tempDigit % 2 == 0) { //One of the digits is not odd => [this num == no]
                    state = false;
                    break;
                }
                
                if (tempDigit % 3 != 0) { //One of the digits is not dividable by 3 => [this num == no]
                    state = false;
                    break;
                } 
             
                //Digit is odd and dividable by 3, to the next digit.
                
                //Simplified version
                // if(tempDigit != 3 || tempDigit != 9) break; //dividable by 3 = 3, 6, 9. Odd: 3, 9;
            }
            
            if (state == true) { // state vẫn == true vì không chữ số nào bị đánh sai
                cout << "Có\n"; // Chỉ cần có là end(Yes/No quest;
                return;
            }
            
        }
    }
    
    cout << "Không có\n";
    return;
}

void isAllElePosOdd(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] <= 0 || a[i] % 2 == 0) {
            cout << "Không\n";
            return;
        }
        
    }
    cout << "Tất cả phần tử Dương và Lẻ";
    return;
    
}