//
// Created by Ziko on 07/06/2023.
//

#ifndef UNTITLED2_SARA_H
#define UNTITLED2_SARA_H

Vehicle* searchVehicleByPlateNumber(char* plateNumber,Vehicle *headv) {
    Vehicle* current;
    current=headv;
    while (current != NULL) {
        if (strcmp(current->plateNr, plateNumber) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void displayAvailablevehicle(Vehicle *headv,Reservation *headr){

    Vehicle* vehicle;
    vehicle=headv;
    Reservation * reservation;
    reservation=headr;

    while(reservation!=NULL) {

        while (vehicle != NULL) {
            if (vehicle->plateNr != reservation->plateNr) {
                printf("Plate Number: %s\n", vehicle->plateNr);
                printf("Year: %d\n", vehicle->year);
                printf("Model: %s\n", vehicle->model);
                printf("Fuel Type: %s\n", vehicle->fType);
                printf("Consumption: %.2f liters per km\n", vehicle->consumption);
                printf("Seats: %d\n", vehicle->seats);
                printf("Daily Price: %.2f\n", vehicle->dPrice);
                printf("\n");

            }
            vehicle=vehicle->next;

        }
        reservation=reservation->next;



    }


}
void createReservation(Reservation **headr,Vehicle *headv) {
    Reservation *newReservation;
    newReservation = (Reservation *) malloc(sizeof(Reservation));

    printf("Enter Reservation ID: ");
    scanf("%d", &newReservation->reservationId);
    printf("Enter Date: ");
    for(int j=0;j<3;j++){
        scanf("%d", &newReservation->date[j]);}
    printf("Enter Client ID: ");
    scanf("%s", newReservation->clientId);
    printf("Enter Number of Days: ");
    scanf("%d", &newReservation->nrDays);
    printf("Enter Plate Number: ");
    scanf("%s", newReservation->plateNr);

    // Calculate total price based on the number of days
    double totalPrice;
    int discount = 0;
    if (newReservation->nrDays >= 7 && newReservation->nrDays < 14) {
        discount = 10;
    } else if (newReservation->nrDays >= 14 && newReservation->nrDays < 30) {
        discount = 15;
    } else if (newReservation->nrDays >= 30) {
        discount = 20;
    }
    totalPrice = discount > 0 ? (1 - (double) discount / 100) * headv->dPrice * newReservation->nrDays : headv->dPrice *
                                                                                                         newReservation->nrDays;
    newReservation->tPrice = totalPrice;
//calculate ending date
    getDateAfterDays(newReservation->date[0], newReservation->date[1],newReservation->date[2],newReservation->nrDays, &(newReservation->diteDorezimi[0]), &(newReservation->diteDorezimi[1]), &(newReservation->diteDorezimi[2]));

    // Add the reservation to the list
    newReservation->next = NULL;
    Reservation *curr;
    curr = *headr;
    if (*headr == NULL) { /* At the beginning for empty list*/
        *headr = newReservation;

    }
    newReservation->next = curr;
    *headr = newReservation;


    printf("Done.\n");
}
void cancelReservation(Reservation **head) {
    if (*head == NULL) {
        printf("No reservations available.\n");
        return;
    }

    int IdRes;
    printf("Enter the reservation ID: ");
    scanf("%d", &IdRes);

    Reservation* current ;
    current=*head;
    Reservation* previous = NULL;

    while (current != NULL) {
        if (current->reservationId == IdRes) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                *head = current->next;
            }
            free(current);
            printf("Reservation canceled successfully.\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Reservation not found.\n");
}


#endif //UNTITLED2_SARA_H
