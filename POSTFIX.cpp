/*
 * Queue
 *
 *  Created on: Oct 12, 2017
 *  Author: Tri Doan
 *  Lab 3
 */

#include <iostream>
#include <string>
#include "Queue.h"
#include "Stack.h"
#include <sstream>


bool HigherPre(string& topvalue, string& component);

using namespace std;
int main()
{
    string equation;
    cout << "Enter the equation or 'p' to quit: ";
    cin >> equation;
    
    stringstream ss(equation);
    string component;
    
    while(equation != 'p')
    {
        while(ss >> component)
        {
            Stack<string> S1;
            Queue<string> Q1;
            if( component != "+" || component != "-" || component != "*" || component != "/")
            {
                Q.enqueue(component);
            }
            else
            {
                if(!empty())
                {
                    string top = S.peek();
                    if(HihgerPre(top, component))
                    {
                        Q.enqueue(top);
                        S.pop();
                        S.push(component);
                    }
                    else  
                    S.push(component);
                }
                else 
                    S.push(component);
            }

        }
    }
}



