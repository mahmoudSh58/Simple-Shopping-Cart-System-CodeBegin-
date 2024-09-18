#include <bits/stdc++.h>
using namespace std;

vector<string> items_name;
vector<double> items_price;
vector<int> items_quantity;

char main_page(){
    cout << "Please select an option:" << '\n';
    cout << "1. Add an item" << '\n';
    cout << "2. View cart" << '\n';
    cout << "3. Remove an item" << '\n';
    cout << "4. Clear cart" << '\n';
    cout << "5. Checkout" << '\n';
    cout << "Enter your choice: ";
    char choice;
    cin >> choice;

    return choice;
}

void add_item(){
    cout << "\n\n";
    cout << "1. Add an item" << '\n';
    cout << "Enter item name: ";
    string name;
    cin >> name;
    cout << "Enter item price: ";
    double price;
    cin >> price;
    cout << "Enter quantity: ";
    int quantity;
    cin >> quantity;

    // add to vector
    items_name.push_back(name);
    items_price.push_back(price);
    items_quantity.push_back(quantity);

    cout << name << " (" << quantity << ") " <<"have been added to the cart at " << price << "$ each." << '\n';
}

void view_cart(){
    cout << "\n\n";
    cout << "2. View cart" << '\n';
    if(items_name.empty()){
            cout << "Your cart is empty." << '\n';
            return;
    }

    cout << "-----------------------------------" << '\n';
    int n = items_name.size();
    double total=0;
    for(int i=0;i<n;i++){
        cout << i+1 << ". " << items_name[i] << ", Quantity: " << items_quantity[i];
        cout << ", Price per unit: $" << items_price[i];
        cout << ", Total: $" << items_price[i] * items_quantity[i] << '\n';

        total += items_price[i] * items_quantity[i];
    }
    cout << "-----------------------------------" << '\n';
    cout << "Total price for all items: $" << total <<'\n';
}

void remove_item(){
    cout << "\n\n";
    cout << "3. Remove an item" << '\n';
    cout << "Enter item name to remove: " ;
    string rm_name;
    cin >> rm_name;

    // search remove items
    int n = items_name.size(),rm_index=-1;
    for(int i=0;i<n;i++){
        if(items_name[i]==rm_name) {rm_index = i;break;}
    }


    if(rm_index == -1){
        // error message
        cout << rm_name << " Not found" << '\n';
    }else {
        // remove
        items_name.erase(items_name.begin()+rm_index);
        items_price.erase(items_price.begin()+rm_index);
        items_quantity.erase(items_quantity.begin()+rm_index);
        cout << rm_name << " has been removed from the cart." << '\n';
    }

}

void clear_cart(){
    cout << "\n\n";
    cout << "4. Clear cart" << '\n';
    while(1){
        cout << "Are you sure you want to clear the cart? (y/n): ";
        char confim;
        cin >> confim;
        if(confim=='y'){
            items_name.clear();
            items_price.clear();
            items_quantity.clear();
            cout << "The cart has been cleared." << '\n';
            break;
        }else if(confim=='n'){
             cout << "OK ,The cart did not clear." << '\n';
             break;
        }else{
            cout << "\n :( |> Invalid Input. Write (\'y\' or \'n\') <|\n\n";
        }
    }
}

void checkout(){
    cout << "\n\n";
    cout << "5. Checkout" << '\n';

    if(items_name.empty()){
            cout << "Your cart is empty." << '\n';
            return;
    }

    cout << "-----------------------------------" << '\n';
    int n = items_name.size();
    double total=0;
    for(int i=0;i<n;i++){
        cout << i+1 << ". " << items_name[i] << ", Quantity: " << items_quantity[i];
        cout << ", Price per unit: $" << items_price[i];
        cout << ", Total: $" << items_price[i] * items_quantity[i] << '\n';

        total += items_price[i] * items_quantity[i];
    }
    cout << "-----------------------------------" << '\n';
    cout << "Total price for all items: $" << total <<'\n';
    items_name.clear();
    items_price.clear();
    items_quantity.clear();
}

int main(){
    cout << "Welcome to the Simple Shopping Cart System!\n";
    cout << fixed << setprecision(2);

    while(1){
        char choice = '9';
        cout << '\n';
        choice = main_page();
        if(choice == '1'){
            add_item();
        }else if(choice == '2'){
            view_cart();
        }else if(choice == '3'){
            remove_item();
        }else if(choice == '4'){
            clear_cart();
        }else if(choice == '5'){
            checkout();
            bool out = false;
            while(1){
                cout << "Would you like to exit? (y/n): ";
                char exit;
                cin >> exit;
                if(exit == 'y'){
                    cout << "Thank you for shopping! Goodbye!";
                    out = true;
                    break;
                }else if(exit == 'n'){
                    cout << "Continue Shopping :) --->" << '\n';
                    break;
                }else{
                    cout << "\n :( |> Invalid Input. Write (\'y\' or \'n\') <|\n\n";
                }
            }
            if(out) break;
        }else {
            cout << "\n :( |> Invalid Input. Write (1-5) <|\n" ;
        }
    }
}
