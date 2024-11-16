#include <iostream>
using namespace std;

class Nilsabetghdam {
private:
    int arr[100] = {};
    int len = 0;
public:
    Nilsabetghdam(int len = 0, int arr[100] = {}){
    }
    void insert(int index, int value) {
        for (int i = len; i >= index; i--) {
            arr[i+1] = arr[i];
        }
        arr[index] = value;
        len++;
    }

    int delete_by_value(int value) {
        for (int i = 0; i <= len;i++){
            if (arr[i] == value) {
                for (int j = i; j <= len; j++) {
                    arr[j] = arr[j + 1];
                }
                len--;
                return i;
            }
        }
        cout << "Not found\n";
        return 0;
    }

    void delete_by_index(int index) {
        for (int i = index; i <= len; i++) {
            arr[i] = arr[i + 1];
        }
        len--;
    }

    void display() {
        for (int i = 0; i < len; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void append(int value) {
        arr[len] = value;
        len++;
    }

    void reverse() {
        for (int i = 0; i < len/2; i++) {
            int temp = arr[i];
            arr[i] = arr[len-1-i];
            arr[len-1-i] = temp;
  
        }

    }

    int search_by_value(int value) {
        for (int i = 0; i < len; i++) {
            if (arr[i] == value) {
                 cout << "index : " << i;
                 return i;
            }
           
        }
        cout << "Not found\n";
        return 0;
    }
};

int main() {
    Nilsabetghdam ns;
    ns.append(10);
    ns.append(6);
    ns.insert(2, 15);
    ns.display();
    ns.delete_by_value(15);
    ns.display();
    ns.reverse();
    ns.display();
    ns.delete_by_index(1);
    ns.display();
    ns.search_by_value(6);
    return 0;
}
