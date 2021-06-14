//You are allowed to define your own function to fulfill the requirement of tasks
//Dont change the name of following functions

/*
*Team Id: eYRC#2060
*Author List: Yogeshwar K, Manoj S, Yashas D, Mangala Madhan Kumar
*Filename: Task_1.c
*Theme: Construct-O-Bot
*Functions: forward_wls(unsigned char node), curve_turn(void), white_line_path(void), left_turn_wls(void), right_turn_wls(void), Task_1_1(void)
*Global Variables: NONE
*/

#include "CB_Task_1_Sandbox.h"

/*
*
* Function Name: forward_wls
* Input: node
* Output: void
* Logic: Uses white line sensors to go forward by the number of nodes specified.
* Example Call: forward_wls(1); //Goes forward by 1 node.It takes values from all the 3 sensorsand converts into digital values(255 or 0).
*               Based on the sensor values if middle sensor is showing a value high and other 2 are low then it moves straight.
*			  	If left sensor shows a high value and other 2 are low, bot moves left. It is similar for right direction also.
*				If 2 or more sensors are giving a value high it is considered as a node and node count is incremmented.Break statement is used to come out of the loop and execute next function.
*				After complete execution of function nodecount values becomes 0.
*/
unsigned char left_sensor, centre_sensor, right_sensor;
void forward_wls(unsigned char node)
{
	unsigned char nodecount = 0;     //variable to count the number of nodes encounterd by the bot

	while (nodecount != node)
	{
		
		while (1)
		{

			left_sensor = ADC_Conversion(1);
			centre_sensor = ADC_Conversion(2);
			right_sensor = ADC_Conversion(3);
			printf("\n %d %d %d", left_sensor, centre_sensor, right_sensor);
			_delay_ms(15);


			if (left_sensor == 0 && centre_sensor == 255 && right_sensor == 0)
			{
				forward();
			}

			else if (left_sensor == 255 && centre_sensor == 0 && right_sensor == 0)
			{
				velocity(20, 255);
			}
			else if (left_sensor == 0 && centre_sensor == 0 && right_sensor == 255)
			{
				velocity(255, 20);

			}
			else if ((left_sensor == 255 && centre_sensor == 255 && right_sensor == 255) || (left_sensor == 255 && centre_sensor == 255 && right_sensor == 0) || (left_sensor == 0 && centre_sensor == 255 && right_sensor == 255))
			{
				nodecount++;
				forward();
				
				break;
			}

		}
	}
	stop();
}

/*
*
* Function Name: curve_turn()
* Input: void
* Output: void
* Logic: Uses white line sensors to go forward by the number of nodes specified.
* Example Call: curve_turn(); //Goes forward by 1 node.Its logic is same as forward_wls function.
*               The only difference is we give a differnt velocity of wheels to complete a curve path.
*			  	
*
*/
void curve_turn(void)
{
	unsigned char nodecount = 0;

	while (nodecount != 1)
	{
		while (1)
		{

			left_sensor = ADC_Conversion(1);
			centre_sensor = ADC_Conversion(2);
			right_sensor = ADC_Conversion(3);
			printf("\n %d %d %d", left_sensor, centre_sensor, right_sensor);
			_delay_ms(10);

			if (left_sensor == 0 && centre_sensor == 255 && right_sensor == 0)
			{
				forward();
			}

			else if ((left_sensor == 255 && centre_sensor == 0 && right_sensor == 0) || (left_sensor == 255 && centre_sensor == 255 && right_sensor == 0))
			{
				velocity(20, 255);
			}
			else if ((left_sensor == 0 && centre_sensor == 0 && right_sensor == 255) || (left_sensor == 0 && centre_sensor == 255 && right_sensor == 255))
			{
				velocity(255, 20);

			}
			else if (left_sensor == 255 && centre_sensor == 255 && right_sensor == 255)
			{
				nodecount++;
				forward();
				break;
			}

			

		}
	}
	stop();

}


/*
*
* Function Name: white_line_path()
* Input: void
* Output: void
* Logic: Uses white line sensors to go forward by the number of nodes specified.
* Example Call: forward_wls(1); //Goes forward by 1 node.This function is used to make the bot on the white line.
*               If middle sensor is showing a value low and other 2 are high then it moves straight.
*			  	If left sensor shows a high value and other 2 are low, bot moves left. It is similar for right direction also.
*				If 2 or more sensors are giving a value high it is considered as a node and node count is incremmented.
*
*
*/

void white_line_path(void)
{
	unsigned char nodecount = 0;

	while (nodecount != 1)
	{
		while (1)
		{
			
			left_sensor = ADC_Conversion(1);
			centre_sensor = ADC_Conversion(2);
			right_sensor = ADC_Conversion(3);
			printf("\n %d %d %d", left_sensor, centre_sensor, right_sensor);
			_delay_ms(15);
			
			if (left_sensor == 0 && centre_sensor == 255 && right_sensor == 0)
			{
				forward();
			}

			else if ((left_sensor == 255 && centre_sensor == 0 && right_sensor == 0) || (left_sensor == 255 && centre_sensor == 255 && right_sensor == 0))
			{
				velocity(20, 255);
			}
			else if ((left_sensor == 0 && centre_sensor == 0 && right_sensor == 255) || (left_sensor == 0 && centre_sensor == 255 && right_sensor == 255))
			{
				velocity(255, 20);

			}
			else if ((left_sensor == 255 && centre_sensor == 255 && right_sensor == 255) ||(left_sensor == 255 && centre_sensor == 255 && right_sensor == 255))
			{
				nodecount++;
				forward();
				break;
			}


			

		}
	}
	stop();

}



void forward_movement(unsigned char node)
{
	unsigned char nodecount = 0;     //variable to count the number of nodes encounterd by the bot

	while (nodecount != node)
	{

		while (1)
		{

			left_sensor = ADC_Conversion(1);
			centre_sensor = ADC_Conversion(2);
			right_sensor = ADC_Conversion(3);
			printf("\n %d %d %d", left_sensor, centre_sensor, right_sensor);
			_delay_ms(50);


			if (left_sensor == 0 && centre_sensor == 255 && right_sensor == 0)
			{
				forward();
			}

			else if (left_sensor == 255 && centre_sensor == 0 && right_sensor == 0)
			{
				velocity(5, 255);
			}
			else if (left_sensor == 0 && centre_sensor == 0 && right_sensor == 255)
			{
				velocity(255, 5);

			}
			else if ((left_sensor == 255 && centre_sensor == 255 && right_sensor == 255) || (left_sensor == 0 && centre_sensor == 0 && right_sensor == 0))
			{
				nodecount++;
				forward();
				_delay_ms(50);
				break;
			}

		}
	}
	stop();
}




unsigned char left_prox_sensor, centre_prox_sensor, right_prox_sensor;
void wall(unsigned char node)
{
	unsigned char nodecount = 0;     //variable to count the number of nodes encounterd by the bot

	while (nodecount != node)
	{

		while (1)
		{

			
			left_prox_sensor = ADC_Conversion(LEFT_IR_ADC_CHANNEL);
			centre_prox_sensor = ADC_Conversion(FRONT_IR_ADC_CHANNEL);
			right_prox_sensor = ADC_Conversion(RIGHT_IR_ADC_CHANNEL);
			printf("\n %d %d %d", left_prox_sensor, centre_prox_sensor, right_prox_sensor);
			_delay_ms(15);

			left_sensor = ADC_Conversion(1);
			centre_sensor = ADC_Conversion(2);
			right_sensor = ADC_Conversion(3);


			if (left_prox_sensor==32 && centre_prox_sensor==32 && right_prox_sensor==32)
			{
				forward();
			}

			else if (left_prox_sensor>32 &&  right_prox_sensor<32)
			{
				soft_left();
				_delay_ms(5);
				forward();
				_delay_ms(2);
			}
			else if (left_prox_sensor<32 &&  right_prox_sensor>32)
			{
				soft_right();
				_delay_ms(5);
				forward();
				_delay_ms(2);
			}


			else if (left_sensor == 0 && centre_sensor == 255 && right_sensor == 0)
			{
				forward();
			}

			else if ((left_sensor == 255 && centre_sensor == 0 && right_sensor == 0) || (left_sensor == 255 && centre_sensor == 255 && right_sensor == 0))
			{
				velocity(20, 255);
			}
			else if ((left_sensor == 0 && centre_sensor == 0 && right_sensor == 255) || (left_sensor == 0 && centre_sensor == 255 && right_sensor == 255))
			{
				velocity(255, 20);

			}
			else if ((left_sensor == 255 && centre_sensor == 255 && right_sensor == 255) || (left_sensor == 255 && centre_sensor == 255 && right_sensor == 0) || (left_sensor == 0 && centre_sensor == 255 && right_sensor == 255))
			{
				nodecount++;
				forward();
				_delay_ms(50);
				break;
			}

		}
	}
	stop();
}









/*
*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until black line is encountered
* Example Call: left_turn_wls(); //Turns right until black line is encountered
*				Intially the bot is turned left by a soft_left() function until left turn is completed with a specific delay.
*				Until the bot is on the black line(left_sensor == 0,centre_sensor == 255,right_sensor == 0) the left function is executed.
*/

void left_turn_wls(void)
{
	
	soft_left();
	_delay_ms(700);
	while (1)
	{

		left_sensor = ADC_Conversion(1);
		centre_sensor = ADC_Conversion(2);
		right_sensor = ADC_Conversion(3);
		printf("\n %d %d %d", left_sensor, centre_sensor, right_sensor);


		if (left_sensor == 0 && centre_sensor == 255 && right_sensor == 0)
		{
			break;
		}
		else
		{
			left();
		}
	}
	stop();
	
}

/*
*
* Function Name: right_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn right until black line is encountered
* Example Call: right_turn_wls(); //Turns right until black line is encountered
*				Intially the bot is turned left by a soft_right() function until left turn is completed with a specific delay.
*				Until the bot is on the black line(left_sensor == 0,centre_sensor == 255,right_sensor == 0) the right function is executed.
*/

void right_turn_wls(void)
{
	stop();
	soft_right();
	_delay_ms(700);
	while (1)
	{

		left_sensor = ADC_Conversion(1);
		centre_sensor = ADC_Conversion(2);
		right_sensor = ADC_Conversion(3);
		printf("\n %d %d %d", left_sensor, centre_sensor, right_sensor);

		if (left_sensor == 0 && centre_sensor == 255 && right_sensor == 0)
		{
			break;
		}
		else
		{
			right();
		}

	}
	stop();
	
}

/*
*
* Function Name: e_shape
* Input: void
* Output: void
* Logic: Use this function to make the robot trace a e shape path on the arena
* Example Call: e_shape();
*/
void e_shape(void)
{

}




















/*
*
* Function Name: Task_1_1
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.1 logic
* Example Call: Task_1_1();
*				All the functions defined above are called in this function.
*/
void Task_1_1(void)
{
	// Write your task 1.1 Logic here
	forward_wls(1);    
	left_turn_wls();


	forward_wls(1);
	right_turn_wls();
	curve_turn();
	stop();           //to stop the movement of bot for few milli seconds
	
	right_turn_wls();
	stop();
	forward_wls(1);
	stop();
	
	left_turn_wls();
	stop();
	forward_wls(1);
	stop();

	right_turn_wls();
	stop();
	forward_wls(1);
	forward();    //forward function with delay is given for the further forward movement of bot in the same direction after it encounters the node
	_delay_ms(200);
	forward_wls(1);
	stop();
	

	left_turn_wls();
	stop();
	curve_turn();
	stop();

	right_turn_wls();
	stop();
	forward_wls(1);
	stop();

	left_turn_wls();
	stop();
	forward_wls(1);
	stop();

	left_turn_wls();
	stop();
	forward_wls(1);
	forward();        //forward function with delay is given for the further forward movement of bot in the same direction after it encounters the node
	_delay_ms(200);
	forward_wls(1);
	stop();
	
	right_turn_wls();
	stop();
	_delay_ms(200);  //to stop the bot for 200 milli seconds
	left();
	_delay_ms(50);
	forward();
	_delay_ms(100);
	white_line_path();
	stop();
	_delay_ms(100);
	
	left_turn_wls();
	stop();
	forward_wls(1);
	stop();
	forward();
	_delay_ms(200);
	forward_wls(1);
	stop();
	
	right_turn_wls();
	stop();
	forward_wls(1);
	stop();




}

/*
*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.2 logic
* Example Call: Task_1_2();
*/
int i, j;

int sarray[2];
int sx, sy, dx, dy;
char arena[7][3] = { {'h','i','j'},
					   {'g','0','k'},
					   {'f','r','l'},
					   {'e','0','m'},
					   {'d','q','n'},
					   {'c','0','o'},
					   {'b','a','p'} };
int herustic[7][3];
char path[7][3] = { {'0','0','0'},
				 {'0','0','0'},
				 {'0','0','0'},
				 {'0','0','0'},
				 {'0','0','0'},
				 {'0','0','0'},
				 {'0','0','0'}
};


void calfind(char des)
{
	sarray[0] = 0;
	sarray[1] = 0;
	char ch = des;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (ch == arena[i][j])
			{
				sarray[0] = i;
				sarray[1] = j;
				printf("x=%d,y=%d\n", sarray[0], sarray[1]);
				break;
			}
		}
	}

}
void calher(char des)
{
	calfind(des);
	dx = sarray[0];
	dy = sarray[1];

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if ((i == 1 && j == 1) || (i == 3 && j == 1) || (i == 5 && j == 1))
			{
				herustic[i][j] = 900;
			}
			else

			{
				herustic[i][j] = abs(dx - i) + abs(dy - j);
			}
		}
	}

}
void imppath(char des, char source)
{
	int temp = 0, pos = 0;
	//find open list 

	calfind(source);
	sx = sarray[0];
	sy = sarray[1];
	int count = 0;
	//intilizing array
	while (herustic[sx][sy] != herustic[dx][dy])
	{


		int openlist[4][2] = {
						 {sx,sy - 1},
						 {sx,sy + 1},
						 {sx - 1,sy},
						 {sx + 1,sy}
		};


		int fcost[4] = { herustic[sx][sy - 1] + 1,herustic[sx][sy + 1] + 1 ,herustic[sx - 1][sy] + 1 ,herustic[sx][sy + 1] + 1 };
		for (i = 0; i < 4; i++)
		{
			temp = fcost[0];
			if (fcost[i] < temp)
			{
				temp = fcost[i];
				pos = i;
			}

		}

		if (pos == 0)
		{
			path[sx][sy] = { '<' };
			sx = sx;
			sy = sy - 1;
			//right_turn_wls();
			//curve_turn();
			//right_turn_wls();

		}
		else if (pos == 1)
		{
			path[sx][sy] = { '>' };
			sx = sx;
			sy = sy + 1;
		//	left_turn_wls();
			//curve_turn();
		}
		else if (pos == 2)
		{
			path[sx][sy] = { '^' };
			sx = sx - 1;
			sy = sy;
			//curve_turn();
		}
		else if (pos == 3)
		{
			path[sx][sy] = { '|' };
			sx = sx + 1;
			sy = sy;
			//back();
		}
		count++;
	}

}
/*
*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.2 logic
* Example Call: Task_1_2();
*/
void Task_1_2(void)
{   //write your task 1.2 logic here

	//curve_turn();

	//for (i = 0; i < 7; i++)
	//{
		//for (j = 0; j < 3; j++)
		//{
			//printf("% c \t", arena[i][j]);

		//}printf("\n");
	//}

	//calher('k');
	//for (i = 0; i < 7; i++)
	//{
		//for (j = 0; j < 3; j++)
		//{
			//printf("% d \t", herustic[i][j]);

		//}printf("\n");
	//}

	//imppath('k ', 'a');
	//path[dx][dy] = { '^' };
	//curve_turn();
	//for (i = 0; i < 7; i++)
	//{
		//for (j = 0; j < 3; j++)
		//{
			//printf("% c \t", path[i][j]);

		//}printf("\n");
	//}


	forward_wls(1);
	
	right_turn_wls();
	forward_wls(1);
	
	right_turn_wls();
	forward_wls(1);
	
	forward();
	_delay_ms(200);
	forward_wls(1);
	//right_turn_wls();
	
	//forward_movement(1);
	//stop();
	//forward_movement(1);
	//stop();
	//forward_movement(1);
	//stop();
	//forward_movement(1);
	//stop();
	//forward_movement(1);
	//stop();
	//forward_movement(1);
	//stop();
	//forward_movement(1);
	//stop();
	//_delay_ms(2000);

	//wall(1);
	//stop();
	//_delay_ms(3000);

	forward_wls(1);
    forward();
	_delay_ms(200);
	forward_wls(1);
	forward();
	_delay_ms(200);
	forward_wls(1);
	forward();
	_delay_ms(200);
	forward_wls(1);
	forward();
	_delay_ms(200);
	forward_wls(1);
	
	right_turn_wls();
	white_line_path();
	_delay_ms(1000);
	right_turn_wls();
	white_line_path();
	_delay_ms(500);
	stop();






}
