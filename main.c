

#include "circle.h"
#include "linkedlist.h"
#include <math.h>
#include "include/raylib.h"
#include"sys/timeb.h"

void updateCircles(Iterator* MyIterator, float t, List* Listptr) {
    for (int i = 0; i < (Listptr->size); i++) {
        if (MyIterator != NULL) {
            if (MyIterator->pCurrentNode != Listptr->pHead) {
                MyIterator->pCurrentNode->pData->ParentX = MyIterator->pCurrentNode->pPrev->pData->ParentX + (MyIterator->pCurrentNode->pData->rodLenght * cos(t * MyIterator->pCurrentNode->pData->w));
                MyIterator->pCurrentNode->pData->ParentY = MyIterator->pCurrentNode->pPrev->pData->ParentY + (MyIterator->pCurrentNode->pData->rodLenght * sin(t * MyIterator->pCurrentNode->pData->w));
            }
            IteratorNext(MyIterator);
        }
    }
}





int main(void)
{

    const int screenWidth = 1920;
    const int screenHeight = 1080;


    Circles* Rootcircle = CircleCreate(BLUE, 30.0f, 50.0f, 0.0f, 960.0f, 540.0f);
    

    List* Listptr = ListCreate();
    Listadd(Listptr, Rootcircle);
    


    Iterator* MyIterator = IteratorCreate(Listptr);
    Iterator* Head = MyIterator;


    



    InitWindow(screenWidth, screenHeight, "Ras_C_Exempt_Project");

    Rectangle Recbutton1 = { 0,0,200,100 };
    Rectangle Recbutton2 = { 0,120,200,100 };
    bool buttonClicked = false;




    SetTargetFPS(60);


    


    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

       
        




         MyIterator=Head;

        if (CheckCollisionPointRec(GetMousePosition(), Recbutton1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            buttonClicked = !buttonClicked;
            if (buttonClicked) {
                float radius = randomize_circle_radius(10,30);
                Color color = randomize_circle_Color();
                float rodLenght = randomize_circle_rodLenght(50,70);
                float w = randomize_circle_w(200, 350);
                float ParentX = MyIterator->pCurrentNode->pPrev->pData->ParentX + rodLenght;
                float ParentY = MyIterator->pCurrentNode->pPrev->pData->ParentY;

                Circles* newcircle = CircleCreate(color, radius, rodLenght, w,ParentX, ParentY);
                Listadd(Listptr, newcircle);
                Listptr->size += 1;

            }
        }
        if (CheckCollisionPointRec(GetMousePosition(), Recbutton2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            buttonClicked = !buttonClicked;
            if (buttonClicked) {
                if (Listptr->pHead && Listptr->pTail == NULL) { return; }
                if(Listptr->pHead!=Listptr->pTail)
                Listrmv(Listptr);
            }
        }


        
        BeginDrawing();

        MyIterator = Head;
        

        updateCircles(MyIterator,GetTime(), Listptr);


        ClearBackground(GRAY);
        
       
        for (int i = 0; i < (Listptr->size); i++) {
            DrawCircle(MyIterator->pCurrentNode->pData->ParentX, MyIterator->pCurrentNode->pData->ParentY, MyIterator->pCurrentNode->pData->radius, MyIterator->pCurrentNode->pData->color);
            IteratorNext(MyIterator);
        }
    

       
        DrawRectangleRec(Recbutton1, YELLOW);
        DrawRectangleRec(Recbutton2, YELLOW);



        for (int i = 1; i <= (Listptr->size); i++) {

            DrawCircle(MyIterator->pCurrentNode->pData->ParentX, MyIterator->pCurrentNode->pData->ParentY, MyIterator->pCurrentNode->pData->radius, MyIterator->pCurrentNode->pData->color);
            if (MyIterator->pCurrentNode->pNext != NULL && MyIterator->pCurrentNode->pNext != Head->pIteratedList->pHead) {
                for (int j =0; j < 20; j++) {
                    float a = -1;
                    DrawLine((int)MyIterator->pCurrentNode->pData->ParentX+a, (int)MyIterator->pCurrentNode->pData->ParentY+a, (int)MyIterator->pCurrentNode->pNext->pData->ParentX+a, (int)MyIterator->pCurrentNode->pNext->pData->ParentY+a, BLUE);
                    a += j / 10;
            }
        }
            IteratorNext(MyIterator);
            }

        DrawText("Add More Circles", 10, 50, 20, BLUE);
        DrawText("Remove Circle", 10, 170, 20, BLUE);
        EndDrawing();
        
        
        
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
        CloseWindow();        // Close window and OpenGL context
       
        return 0;
    
}



