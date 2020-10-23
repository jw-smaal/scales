/**
 * @file midi-scales.cpp
 * @author Jan-Willem Smaal <usenet@gispen.org> 
 * @date 3/9/2020 
 * @copyright APACHE-2.0 
 */
#include "midi-scales.h" 
#include <iostream> 
#include <string> 


int main()
{
	int i,j; 
	uint8_t rootnote = 42; 
//	uint8_t rootnote = 60; 


	// Since a enum is just an int we can cast 
	// i know there is better way to do this in C++ 
	for(j = CHROMATIC; j <= MINOR_PENTATONIC; j++) {
		Scale scl((enum scaleKinds)j, rootnote);
		for(i = 0; i < scl.modes; i++) {
			scl.SetMode(i); 		
			std::cout << scl.scaleName 
					  << " scale in mode " 
					  << scl.modeName 
					  << std::endl;
			std::cout << scl.Text(rootnote, true) << ": ";  
			std::cout << scl.Text(rootnote, false) << ": ";  
			Chord chord(&scl, Chord::BASIC, rootnote);
			std::cout << chord.Text(true) << ": ";  
			std::cout << chord.Text(false); 
			std::cout << std::endl;  
			std::cout << std::endl;  
		}
		if(scl.modes == 0 ) {
			std::cout << scl.Text(rootnote, true) << std::endl;  
			std::cout << scl.Text(rootnote, false) << std::endl;  
			Chord chord(&scl, Chord::BASIC, rootnote);
			std::cout << "Chord " << chord.Text(true); 
			std::cout << "Chord " << chord.Text(false); 
			std::cout << std::endl;
		}	
	}	


#if 0
	// Interate through the 7 modes
	for(j = 0; j < 7; j++) {
		// List the scale for all the 12 rootnotes 
		for(i = 0; i < 12; i++) {
			Scale mymajor(MAJOR,j);
			std::cout << "MAJOR (mode): " << (unsigned int)mymajor.mode 
				<< ":"	
				<< mymajor.Text(i, false)  
				<< std::endl;  
		}
	}

	for(j = 0; j < 7; j++) {
		for(i = 0; i < 12; i++) {
			Scale myminor(MINOR,j);
			std::cout << "MINOR (mode): " << (unsigned int)myminor.mode 
				<< ":"	
				<< myminor.Text(i, false)  
				<< std::endl;  
		}
	}


#endif 

#if 0 

	Scale scale8(CHROMATIC,0); 
	std::cout << "Chromatic:" << scale8.Text(rootnote, true) << std::endl;  
	std::cout << "Chromatic:" << scale8.Text(rootnote, false) << std::endl;  
	std::cout << std::endl;  


	Scale scale1(GYPSY,0); 
	std::cout << "Gypsy:" << scale1.Text(rootnote, true) << std::endl;  
	std::cout << "Gypsy:" << scale1.Text(rootnote, false) << std::endl;  
	std::cout << std::endl;  

	Scale scale2(MAJOR, 0); 
	std::cout << "Major:" << scale2.Text(rootnote, true) << std::endl;
	std::cout << std::endl;  

	Scale scale3(MINOR, 0); 
	std::cout << "Minor:" << scale3.Text(rootnote, true) << std::endl;  
	std::cout << std::endl;  

	Scale scale4(GYPSY,0); 
	std::cout << "Gypsy:" << scale4.Text(rootnote, true) << std::endl;  
	std::cout << std::endl;  

	Scale scale5(BLUES_MAJOR, 0); 
	std::cout << "Blues Major:" << scale5.Text(rootnote, true) << std::endl;  
	std::cout << std::endl;  

	Scale scale6(BLUES_MINOR, 1); 
	std::cout << "Blues Minor:" << scale6.Text(rootnote, true) << std::endl;  
	std::cout << std::endl;  

	Scale scale7(GYPSY,0); 
	std::cout << "Gypsy:" << scale7.Text(rootnote, true) << std::endl;  
	std::cout << std::endl;  
#endif 


//  list all the MIDI note numbers 
//	for(i = 0; i < 128; i++){
//		std::cout << i << ":" << scale7.NoteToText(i,true) << std::endl; 
//	}


	return 0; 
}

/* EOF */ 
