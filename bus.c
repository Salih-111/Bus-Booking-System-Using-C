#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SEATS 30
#define MAX_NAME_LENGTH 50

struct Booking
{
    char name[MAX_NAME_LENGTH];
    int seatNo;
    char source[MAX_NAME_LENGTH];
    char destination[MAX_NAME_LENGTH];

};
struct Booking bookings[MAX_SEATS];
int bookedSeats = 0;

void bookSeat(){
    if (bookedSeats >= MAX_SEATS){
        printf("All seats are booked!\n");
        return;
    }
    struct Booking newBooking;
    printf("Enter your name: ");
    scanf("%s", newBooking.name);
    printf("Enter seat number : ");
    scanf("%d", &newBooking.seatNo);
    printf("Enter source: ");
    scanf("%s", newBooking.source);
    printf("Enter destination: ");
    scanf("%s", newBooking.destination);

    bookings[bookedSeats++] = newBooking;
    printf("Seat booked successfully!\n");

}

void viewReservations() {
    if (bookedSeats == 0) {
        printf("No reservations found!\n");
        return;
    }

    printf("All Reservations:\n");
    printf("%-10s %-20s %-15s %-15s\n", "Seat No.", "Name", "Source", "Destination");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < bookedSeats; ++i) {
        printf("%-10d %-20s %-15s %-15s\n",
               bookings[i].seatNo,
               bookings[i].name,
               bookings[i].source,
               bookings[i].destination);
    }
}


void editReservation(){
    int seatToEdit;
    printf("Enter seat number to edit: ");
    scanf("%d", &seatToEdit);

    int found = 0;
    for (int i = 0; i < bookedSeats; ++i){
        if (bookings[i].seatNo == seatToEdit){
            printf("Enter new name: ");
            scanf("%s", bookings[i].name);
            printf("Enter new source: ");
            scanf("%s", bookings[i].source);
            printf("Enter new destination: ");
            scanf("%s", bookings[i].destination);
            
            printf("Reservation updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found){
        printf("Reservation not found!\n");
    }
}

void printTicket(){
    int seatToPrint;
    printf("Enter seat number to print ticket: ");
    scanf("%d", &seatToPrint);

    int found = 0;
    for (int i = 0; i < bookedSeats; ++i){
        if (bookings[i].seatNo == seatToPrint){
            printf("Ticket for Seat No. %d,n", bookings[i].seatNo);
            printf("Passenger Name: %s,n", bookings[i].name);
            printf("Passenger Source: %s,n", bookings[i].source);
            printf("Passenger Destination: %s,n", bookings[i].destination); 
            found = 1;
            break;
        }
    }
    if (!found){
        printf("Reservation not found!\n");
    }
}



int main(){
    int choice;
    do {
        printf("Bus Ticket Booking System\n");
        printf("1. Book Ticket\n");
        printf("2. View Reservations\n");
        printf("3. Edit Reservation\n");
        printf("4. Print Ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                bookSeat();
                break;
            case 2:
                viewReservations();
                break;
            case 3:
                editReservation();
                break;
            case 4:
                printTicket();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }   
    } while (choice != 5);
    return 0;
}
