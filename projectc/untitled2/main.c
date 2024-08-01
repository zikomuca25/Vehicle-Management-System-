#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"struct.h"
#include"ziko.h"
#include"jusra.h"
#include"sara.h"
#include "juna.h"
int cntV=0;
int cntR=0;
int cntC=0;

int main() {
    //system("color 03");
    printf("+--------------------------------------------------------------------------------+\n");
    printf("|                        VEHICLE RENTAL APP by gummy bears                       |\n");
    printf("+--------------------------------------------------------------------------------+\n");


    printf("\n\n");

    printf("-------------WELCOME TO OUR VEHICLE RENTAL APPLICATION!------------\n");
    int day[3]={0,0,0};
    printf("Enter the date(dd mm yy):\n");
    for(int i=0;i<3;i++)
        scanf("%d",&day[i]);

    int choice;
    FILE *fpV;
    fpV=fopen("C:\\Users\\Ziko\\Desktop\\unititled2\\vehicle.txt","r");
    if(fpV==NULL){
        printf("Cant open vehicle file");
        return 0;
    }
    FILE *fpR;
    fpR=fopen("C:\\Users\\Ziko\\Desktop\\unititled2\\reservation.txt","r");
    if(fpR==NULL){
        printf("Cant open reservation file");
        return 0;
    }
    FILE *fpC;
    fpC=fopen("C:\\Users\\Ziko\\Desktop\\unititled2\\client.txt","r");
    if(fpC==NULL){
        printf("Cant open client file");
        return 0;
    }

    Vehicle *headv=NULL;
    insertVehicleFileE(&headv,fpV,&cntV);//ketu ke te gjitha makinat si link list
    Reservation *headr=NULL;

    insertReservationFileB(&headr,fpR,&cntR);
    Client *headc=NULL;

    insertClientFileE(&headc,fpC,&cntC);

    fclose(fpC);
    fclose(fpR);
    fclose(fpV);

    do  {
        printf("\n");

        printf("+-------------------------------MENU------------------------------+\n");
        printf("|                                                                 |\n");
        printf("|------------------------------CLIENT-----------------------------|\n");
        printf("|  1.  Display all clients                                        |\n");
        printf("|  2.  Add a new client                                           |\n");
        printf("|  3.  Remove a client                                            |\n");
        printf("|  4.  Display clients with more than 3 rentals                   |\n");
        printf("|                                                                 |\n");
        printf("|-----------------------------VEHICLE-----------------------------|\n");
        printf("|  5.  Display all vehicles                                       |\n");
        printf("|  6.  Display available vehicles                                 |\n");
        printf("|  7.  Display vehicles available after x days                    |\n");
        printf("|  8.  Add a new vehicle                                          |\n");
        printf("|  9.  Search for a vehicle using the license plate number        |\n");
        printf("|  10. Sort and display vehicles by daily rental price            |\n");
        printf("|  11. Display the top 3 most reserved vehicles                   |\n");
        printf("|  12. Remove a vehicle                                           |\n");
        printf("|  13. Modify information for a vehicle using its plate number    |\n");
        printf("|                                                                 | \n");
        printf("|----------------------------RESERVATION--------------------------|\n");
        printf("|  14. Create a new reservation                                   |\n");
        printf("|  15. Display all reservations                                   |\n");
        printf("|  16. Cancel a reservation                                       |\n");
        printf("|  17. Save reservations exceeding a certain cost to a file       |\n");
        printf("|                                                                 |\n");
        printf("|-------------------------------EXIT------------------------------|\n");
        printf("|  0. Exit                                                        |\n");
        printf("+-----------------------------------------------------------------+\n");


        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayAllClient(headc);
                break;
            case 2:
                addClient(&headc);
                   cntR++;
                break;
            case 3:
                removeClient(&headc);
                cntR--;
                break;
            case 4:
                displayClientsWithMoreThan3Rentals(headc,headr);

                break;
            case 5:
                displayAllVehicles(headv);

                break;
            case 6:
            {


                displayAvailablevehicle(headv,headr);
                break;}

            case 7:{
                int days;
                printf("Enter the nr of days-");
                scanf("%d",&days);
                displayVehiclesAfterDay(headr,days,cntR,headv,day);
                break;}
            case 8:
                addVehicle(&headv) ;
                cntV++;
                break;
            case 9:{
                char platenr[20];
                printf("Enter the plate nr:");
                scanf("%s",platenr);
                Vehicle *p=NULL;
                p=searchVehicleByPlateNumber( platenr,headv);
                Vehicle *newNode;
                newNode=headv;
                while(newNode!=NULL){
                    if(newNode==p){
                        printf("Plate Nr- %s\nModel- %s\nYear- %d\nFuel Type- %s\nConsumption- %.1f\nNr of Seats: %d\nDaily Price- %.2f\n", newNode->plateNr,newNode->model,newNode->year,newNode->fType, newNode->consumption,newNode->seats,newNode->dPrice);
                    }
                    newNode=newNode->next;
                }

                break;}
            case 10:
                bubbleSortdPrice( headv);
                //displayAllVehicles(headv);
                break;
            case 11:
                displayTop3ReservedVehicles(headv,headr);

                break;
            case 12:{

                removeVehicle(&headv);
                cntV--;
                break;}
            case 13:
            {

                char plateNumber[20];
                printf("Enter the license plate number: ");
                scanf("%s", plateNumber);
                Vehicle* vehicle = searchVehicleByPlateNumber(plateNumber,headv);
                if (vehicle != NULL) {
                    printf("Vehicle found:\n");

                    printf("Enter modified information:\n");
                    printf("Year: ");
                    scanf("%d", &(vehicle->year));
                    printf("Model: ");
                    scanf("%s", vehicle->model);
                    printf("Fuel Type: ");
                    scanf("%s", vehicle->fType);
                    printf("Consumption: ");
                    scanf("%lf", &(vehicle->consumption));
                    printf("Nr of Seats: ");
                    scanf("%d", &(vehicle->seats));
                    printf("Daily Price: ");
                    scanf("%lf", &(vehicle->dPrice));
                    printf("Vehicle information updated.\n");
                } else {
                    printf("Vehicle not found.\n");
                }
                break;
            }

            case 14:
                createReservation(&headr,headv);
                cntR++;
                break;
            case 15:
                displayAllReservations(headr);

                break;
            case 16:
                cancelReservation(&headr) ;
                cntR--;
                break;
            case 17:
            {
                double givenCost;
                printf("Enter the curtain cost: ");
                scanf("%lf",&givenCost);
                saveReservationsExceedingCost(headr, givenCost);

                break;
            }
            case 0:
                printf("Exiting...\n");
                ReservationListToFile(headr,cntR);
                ClientListToFile(headc,cntC);
                VehicleListToFile(headv,cntV);
                printf("Thank you for using our program!\nHave a nice day!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while (choice != 0);





    return 0;
}
