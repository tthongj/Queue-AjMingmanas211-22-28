#include <iostream>
#include "queue.h"
using namespace std;

int main(int argc, char *argv[]) {
  Queue q;
  int i, price, money, change;
  int queueCount = 0, pplCount = 0;
  char menu[3][30] = {"Ramen", "Somtum", "Fried chicken"};

  for (i = 1; i < argc; i++) {
    if (argv[i][0] == 'x') {
      if (pplCount > 0) {
        cout << "Customer no: " << queueCount + 1 << endl;
        price = q.dequeue();
        // Ask the customer to pay
        
        cout << "You have to pay: " << price << endl;
        do {
          cout << "Cash: ";
          cin >> money;
        } while (money < price);
        if (money > price) {
          change = money - price;
          cout << "Change: " << change << endl;
        }
        cout << "Thank you" << endl;
        queueCount++;
        pplCount--;
      } else {
        cout << "No items in the queue." << endl;
      }
    } else {
      if (i+1 < argc) {
        int ord_number = atoi(argv[i]);
        int qty = atoi(argv[i+1]);
        q.enqueue(ord_number, qty);
        i++;
        pplCount++;
      } else {
        cout << "Invalid input." << endl;
      }
    }
  }
  cout<<"===============\n";
  (pplCount!=0) ? cout<<"There are "<<pplCount<<" ppl left in the queue.\n": cout<<"No one was left in the queue.\n";
  
  return 0;
}