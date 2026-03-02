#include <iostream>
#include <string>
using namespace std;
class show {
public:
    string moviename;
    string showtime;
    int base_ticket_price;
    int total_seats;
    int bookedseats[9];
    int seat_no;
    show() {}
    show(string mn, string st, int price, int seats, int bs[]) {
        moviename = mn;
        showtime = st;
        base_ticket_price = price;
        total_seats = seats;
        for (int i = 0; i < 9; i++)
            bookedseats[i] = bs[i];
    }
    virtual int calculatePrice() {
        return base_ticket_price;
    }
    void Book_seats() {
        cout << "Enter seat no. you want to book: ";
        cin >> seat_no;
        try {
            if (seat_no < 1 || seat_no > 50)
                throw string("Invalid seat number! Seat must be between 1 and 50.");
            for (int i = 0; i < 9; i++) {
                if (bookedseats[i] == seat_no)
                    throw string("Seat is already booked!");
            }
            cout << "Seat is available.\n";
        } catch (string error) {
            cout << error << endl;
        }
    }
    show operator+(show &other) {
        int newBooked[9] = {0};
        int index = 0;

        for (int i = 0; i < 9; i++) {
            if (bookedseats[i] != 0 && index < 9)
                newBooked[index++] = bookedseats[i];
        }
        for (int i = 0; i < 9; i++) {
            bool exists = false;

            for (int j = 0; j < 9; j++) {
                if (newBooked[j] == other.bookedseats[i])
                    exists = true;
            }
            if (!exists && other.bookedseats[i] != 0 && index < 9)
                newBooked[index++] = other.bookedseats[i];
        }
        return show(moviename, showtime, base_ticket_price, total_seats, newBooked);
    }
    void showinfo() {
        cout << "\n--- RECEIPT ---\n";
        cout << "Movie Name: " << moviename << endl;
        cout << "Show Time: " << showtime << endl;
        cout << "Base Ticket Price: " << base_ticket_price << endl;
        cout << "Booked Seat: " << seat_no << endl;
    }
};
class show2D : public show {
public:
    int extra_2d_charges;

    show2D(string mn, string st, int price, int seats, int bs[]): show(mn, st, price, seats, bs) 
    {
        extra_2d_charges = 50;
    }
    int calculatePrice() {
        return base_ticket_price + extra_2d_charges;
    }
};
class show3D : public show {
public:
    int extra_3D_charges;
    show3D(string mn, string st, int price, int seats, int bs[]): show(mn, st, price, seats, bs)
    {
        extra_3D_charges = 100;
    }
    int calculatePrice() {
        return base_ticket_price + extra_3D_charges;
    }
};
class premiumshow : public show {
public:
    int lounge_fee;
    int premium_charges;
    premiumshow(string mn, string st, int price, int seats, int bs[]): show(mn, st, price, seats, bs)
    {
        lounge_fee = 120;
        premium_charges = 200;
    }

    int calculatePrice() {
        return base_ticket_price + lounge_fee + premium_charges;
    }
};
int main() {
    int booked1[9] = {0};
    cout << "\nChoose Show Type:\n";
    cout << "1. Normal\n2. 2D\n3. 3D\n4. Premium\n";
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        show s("MovieA", "7PM", 1000, 50, booked1);
        s.Book_seats();
        cout << "Final Price: " << s.calculatePrice();
        s.showinfo();
    }

    if (choice == 2) {
        show2D d2("MovieB", "8PM", 1500, 50, booked1);
        d2.Book_seats();
        cout << "Extra 2D Charges: " << d2.extra_2d_charges << endl;
        cout << "Final Price: " << d2.calculatePrice();
        d2.showinfo();
    }
    if (choice == 3) {
        show3D d3("MovieC", "9PM", 2000, 50, booked1);
        d3.Book_seats();
        cout << "Extra 3D Charges: " << d3.extra_3D_charges << endl;
        cout << "Final Price: " << d3.calculatePrice();
        d3.showinfo();
    }
    if (choice == 4) {
        premiumshow p("MovieP", "10PM", 2500, 50, booked1);
        p.Book_seats();
        cout << "Lounge Fee: " << p.lounge_fee 
             << ", Premium Charges: " << p.premium_charges << endl;
        cout << "Final Price: " << p.calculatePrice();
        p.showinfo();
    }
    show2D s1("Movie1", "6PM", 300, 50, booked1);
    show3D s2("Movie2", "5PM", 200, 40, booked1);

    cout << "\nMERGING BOOKINGS...\n";
    show merged = s1 + s2;

    cout << "Merged booked seats: ";
    for (int i = 0; i < 9; i++) {
        if (merged.bookedseats[i] != 0)
            cout << merged.bookedseats[i];
    }
    cout << endl;

    return 0;
}
