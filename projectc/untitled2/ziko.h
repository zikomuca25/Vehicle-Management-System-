//
// Created by Ziko on 07/06/2023.
//

#ifndef UNTITLED2_ZIKO_H
#define UNTITLED2_ZIKO_H



#include "jusra.h"
//files
void ClientListToFile(Client *head,int n) {
    FILE* file = fopen("C:\\Users\\Ziko\\Desktop\\unititled2\\client.txt", "w");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }
    fprintf(file, "%d\n", n);

    Client* current = head;
    while (current != NULL) {
        fprintf(file, "%s ", current->clientId);
        fprintf(file, "%s %s ", current->name, current->surname);
        fprintf(file, "%d ", current->passportId);
        fprintf(file, "%s ", current->state);
        fprintf(file, "%d\n", current->phoneNr);
        //  fprintf(file, "\n");
        current = current->next;
    }

    fclose(file);
    printf("Client list saved to file successfully.\n");
}
void VehicleListToFile(Vehicle*head,int n) {
    FILE* file = fopen("C:\\Users\\Ziko\\Desktop\\unititled2\\vehicle.txt", "w");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }
    fprintf(file, "%d\n", n);

    Vehicle* current = head;
    while (current != NULL) {
        fprintf(file, "%s ", current->plateNr);
        fprintf(file, "%s ", current->model);
        fprintf(file, "%d ", current->year);

        fprintf(file, "%s ", current->fType);
        fprintf(file, "%.2f ", current->consumption);
        fprintf(file, "%d ", current->seats);
        fprintf(file, "%.2f\n", current->dPrice);
        //fprintf(file, "\n");
        current = current->next;
    }

    fclose(file);
    printf("Vehicle list printed to file successfully.\n");
}
void ReservationListToFile(Reservation *head,int n) {
    FILE* file = fopen("C:\\Users\\Ziko\\Desktop\\unititled2\\reservation.txt", "w");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }
    fprintf(file, "%d\n", n);


    Reservation* current = head;
    while (current != NULL) {
        fprintf(file, "%d ", current->reservationId);
        for(int j=0;j<3;j++)
            fprintf(file, "%d ", current->date[j]);
        fprintf(file, "%s ", current->clientId);
        fprintf(file, "%d ", current->nrDays);
        fprintf(file, "%lf ", current->tPrice);
        fprintf(file, "%s ", current->plateNr);
        for(int j=0;j<3;j++){
            if(j==2)
                fprintf(file, "%d\n", current->diteDorezimi[j]);
            else
                fprintf(file, "%d ", current->diteDorezimi[j]);

        }

        //fprintf(file, "\n");
        current = current->next;
    }

    fclose(file);
    printf("Reservation list saved to file successfully.\n");
}
void insertVehicleFileE(Vehicle **head, FILE *fp1,int *n){
    Vehicle *newNode,*curr,*prev;
    fscanf(fp1,"%d",n);//
    for(int i=0;i<*n;i++) {
        newNode = (Vehicle *) malloc(sizeof(Vehicle));

        fscanf(fp1, "%s %s %d %s %lf %d %lf", newNode->plateNr, newNode->model, &newNode->year, newNode->fType,
               &newNode->consumption, &newNode->seats, &newNode->dPrice);
        newNode->next = NULL;
        if (*head == NULL) { /* At the beginning for empty list*/
            *head = newNode;
        }
        curr = *head;
        while (curr != NULL) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) /* At the end */
        {
            prev->next = newNode;
            newNode->next = NULL;
        }
    }
}
void insertClientFileE(Client **head,FILE *fp1,int *n){

    Client *newNode=NULL,*curr=NULL,*prev=NULL;
    fscanf(fp1,"%d",n);

    for(int i=0;i<*n;i++) {

        newNode = (Client *) malloc(sizeof(Client));

        fscanf(fp1, "%s %s %s %d %s %d", newNode->clientId, newNode->name, newNode->surname,&newNode->passportId,newNode->state, &newNode->phoneNr);
        newNode->next = NULL;
        if (*head == NULL) { /* At the beginning for empty list*/
            *head = newNode;
        }
        curr = *head;
        while (curr != NULL) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) /* At the end */
        {
            prev->next = newNode;
            newNode->next = NULL;
        }
    }
}
void insertReservationFileB(Reservation **head,FILE *fp1,int *n){//hidhi nje sy prap te pjesa e date dhe dita e dorezimit
    Reservation *newNode;

    fscanf(fp1,"%d",n);
    for(int i=0;i<*n;i++){
        newNode = (Reservation *) malloc(sizeof(Reservation ));
        fscanf(fp1,"%d ", &newNode->reservationId);

        for(int j=0;j<3;j++){
            fscanf(fp1,"%d ", &newNode->date[j]);
            // printf("%d",newNode->date[j]);


        }

        fscanf(fp1,"%s %d %lf %s ",newNode->clientId, &newNode->nrDays, &newNode->tPrice,newNode->plateNr);
        for(int j=0;j<3;j++){
            fscanf(fp1,"%d ", &newNode->diteDorezimi[j]);

        }
        newNode->next = NULL;
        Reservation *curr;
        curr = *head;
        if (*head==NULL){ /* At the beginning for empty list*/
            *head = newNode;
        }
        newNode->next=curr;
        *head=newNode;}
}
//funksionet Ziko

//printf("|  10. Sort and display vehicles by daily rental price            |\n");
void swapNodes(Vehicle * node1, Vehicle  *node2) {

    int temp = node1->year;
    node1->year = node2->year;
    node2->year = temp;

    double temp2 = node1->consumption;
    node1->consumption = node2->consumption;
    node2->consumption = temp2;

    double temp3 = node1->dPrice;
    node1->dPrice = node2->dPrice;
    node2->dPrice = temp3;

    int temp4 = node1->seats;
    node1->seats = node2->seats;
    node2->seats = temp4;
    char temp5[20];
    strcpy(temp5, node1->plateNr);
    strcpy(node1->plateNr, node2->plateNr);
    strcpy(node2->plateNr, temp5);
    char temp6[20];
    strcpy(temp6, node1->model);
    strcpy(node1->model, node2->model);
    strcpy(node2->model, temp6);
    char temp7[20];
    strcpy(temp7, node1->fType);
    strcpy(node1->fType, node2->fType);
    strcpy(node2->fType, temp7);

}
void bubbleSortdPrice(Vehicle * head) {
    int swapped;
    Vehicle* ptr1;
    Vehicle * lptr = NULL;
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->dPrice > ptr1->next->dPrice) {
                // Swap the nodes
                swapNodes(ptr1,ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    displayAllVehicles(head);
}
//printf("|  17. Save reservations exceeding a certain cost to a file       |\n");
void saveReservationsExceedingCost(Reservation *head,double givenCost) {
    FILE *fp;
    fp = fopen("C:\\Users\\Ziko\\Desktop\\unititled2\\cost.txt", "a");

    if (head == NULL) { return; }
    Reservation *current = NULL;
    current = head;
    while (current != NULL) {
        if (current->tPrice > givenCost) {
            fprintf(fp, "Reservation ID- %d\n", current->reservationId);
            fprintf(fp, "Date-");


            for (int i = 0; i < 3; i++) {
                fprintf(fp, "%d/", current->date[i]);
            }

            fprintf(fp, "Client ID- %s\n", current->clientId);
            fprintf(fp, "Nr of Days- %d\n", current->nrDays);
            fprintf(fp, "Plate Nr- %s\n", current->plateNr);
            fprintf(fp, "Total Price- %.2lf\n", current->tPrice);
            fprintf(fp, "Booking End Date-");
            for (int i = 0; i < 3; i++) {
                fprintf(fp, "%d ", current->diteDorezimi[i]);
            }

            fprintf(fp, "\n");
        }
        current = current->next;
    }

    fclose(fp);
    printf("Reservations saved to file successfully.\n");
}

int LeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

// Function to get the number of days in a given month of a year
int getDaysInMonth(int month, int year) {
    int Month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && LeapYear(year))
        return 29;
    else
        return Month[month - 1];
}

// Function to calculate the date after a given number of days
void getDateAfterDays(int day, int month, int year, int numDays, int *fDay, int *fMonth, int *fYear) {

    *fDay = day;
    *fMonth = month;
    *fYear = year;

    while (numDays > 0) {
        int daysInMonth = getDaysInMonth(*fMonth, *fYear);
        int remainingDays = daysInMonth - *fDay + 1;

        if (numDays <= remainingDays) {
            *fDay += numDays;
            break;
        } else {
            numDays -= remainingDays;
            *fDay = 1;

            if (*fMonth == 12) {
                *fMonth = 1;
                *fYear += 1;
            } else {
                *fMonth += 1;
            }
        }
    }
}
int compare(int day1, int month1, int year1, int day2, int month2, int year2) {
    if (year1 < year2)
        return -1;
    else if (year1 > year2)
        return 1;
    else {
        if (month1 < month2)
            return -1;
        else if (month1 > month2)
            return 1;
        else {
            if (day1 < day2)
                return -1;
            else if (day1 > day2)
                return 1;
            else
                return 0;
        }
    }
}

//printf("|  7.  Display vehicles available after x days                    |\n");

void displayVehiclesAfterDay(Reservation * head, int days,int n ,Vehicle *headv,int *ditaesotme) {
    printf("Vehicles available after %d days:\n", days);
    int day1[3]={0,0,0};
    getDateAfterDays(ditaesotme[0],ditaesotme[1],ditaesotme[2],days,&day1[0],&day1[1],&day1[2]);
    Reservation *current;
    current = head;
    int Result;
    char array[n][20];
    int i = 0;

    Vehicle *fixed;
    fixed = headv;
    while (current != NULL) {
        Result = compare(current->diteDorezimi[0], current->diteDorezimi[1], current->diteDorezimi[2], day1[0],
                         day1[1], day1[2]);

        if (Result < 0) {
            strcpy(array[i], current->plateNr);
            i++;


        }
        current = current->next;

    }
    i=0;

    while (fixed != NULL) {
        for(int j=0;j<n;j++) {
            if (strcmp(fixed->plateNr, array[j]) == 0) {
                printf("Info nr %d\n", i + 1);
                printf("............\n");

                printf("Plate Number: %s\n", fixed->plateNr);
                printf("Model: %s\n", fixed->model);
                printf("Year: %d\n", fixed->year);
                printf("Fuel Type: %s\n", fixed->fType);
                printf("Fuel Consumption: %.1f\n", fixed->consumption);
                printf("Number of Seats: %d\n", fixed->seats);
                printf("Daily Price: %.2f\n", fixed->dPrice);
                printf("\n");

            }
        }
        fixed = fixed->next;
    }
}




void displayAllClient(Client *head){
    if (head==NULL){
        printf("No client:(!\n");
        return;}
    Client *curr=NULL;
    curr=head;
    int i=0;
    while (curr!=NULL)
    {   printf("Info nr %d\n",i+1);
        printf("............\n");

        printf("Client Id: %s\n", curr->clientId);
        printf("Name: %s\n", curr->name);
        printf("Surname: %s\n", curr->surname);
        printf("Passport Id %d\n", curr->passportId);
        printf("State: %s\n", curr->state);
        printf("Phone Number: %d\n", curr->phoneNr);
        printf("\n");
        curr=curr->next;
        i++;
    }
}
void addClient(Client **head) {
    Client *newVehicle,*curr,*prev;
    newVehicle = (Client *) malloc(sizeof(Client));

    printf("Enter Client Id: ");
    scanf("%s", newVehicle->clientId);
    printf("Enter name: ");
    scanf("%s", (newVehicle->name));
    printf("Enter surname: ");
    scanf("%s", newVehicle->surname);
    printf("Enter Passport id: ");
    scanf("%d", &newVehicle->passportId);
    printf("Enter state: ");
    scanf("%s", newVehicle->state);
    printf("Enter Phone Number: ");
    scanf("%d", &(newVehicle->phoneNr));


    newVehicle->next = NULL;
    curr = *head;
    while ( curr != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) /* At the end */
    {
        prev->next = newVehicle;
        newVehicle->next = NULL;
    }
    printf("Client added successfully.\n");
}
void removeClient(Client**head) {
    if (*head == NULL) {
        printf("No client.\n");
        return;
    }

    char plateNumber[20];
    printf("Enter the client Id: ");
    scanf("%s", plateNumber);

    Client* current ;
    current=*head;
    Client* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->clientId, plateNumber) == 0) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                *head = current->next;
            }
            free(current);
            printf("Client removed successfully.\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Client not found.\n");
}



#endif //UNTITLED2_ZIKO_H
