/*
 * tracker.h
 *
 *  Created on: Sep 22, 2021
 *      Author: Ben De Lathouwer
 */

#ifndef INC_TRACKER_H_
#define INC_TRACKER_H_

// suport functions
int GPSChecksumGen(const char*);


//io functions
void noise(int);
void ssr(int);


//rtc functions

int  SetTime (int,int,int,int,int,int,int);
void GetTime (void);
#endif /* INC_TRACKER_H_ */
