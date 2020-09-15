/**
 * @file midi-scales.hpp 
 * @author Jan-Willem Smaal <usenet@gispen.org> 
 * @date 3/9/2020 
 * @copyright BSD 
 */
#ifndef __midi_scales_h_hpp
#define __midi_scales_h_hpp 

#include <inttypes.h>
#include <string>

/*
 * "Intervallen" in Dutch
 */
#define PRIME               0
#define KLEINE_SECUNDE      1
#define GROTE_SECUNDE       2
#define KLEINE_TERTS        3
#define GROTE_TERTS         4
#define REINE_KWART         5
#define OVERMATIGE_KWART    6
#define VERMINDERDE_KWINT   6
#define TRITONUS            6
#define REINE_KWINT         7
#define KLEINE_SEXT         8
#define GROTE_SEXT          9
#define KLEINE_SEPTIEM     10
#define GROTE_SEPTIEM      11
#define OCTAAF             12

/*
 * Intervals in ENGLISH with the DUTCH equivalent
 */
#define PERFECT_UNISON      PRIME               // 0
#define AUGMENTED_UNISON    KLEINE_SECUNDE      // 1
#define MINOR_SECOND        KLEINE_SECUNDE      // 1
#define MAJOR_SECOND        GROTE_SECUNDE       // 2
#define AUGMENTED_SECOND    KLEINE_TERTS        // 3
#define MINOR_THIRD         KLEINE_TERTS        // 3
#define MAJOR_THIRD         GROTE_TERTS         // 4
#define PERFECT_FOURTH      REINE_KWART         // 5
#define TRITONE             OVERMATIGE_KWART    // 6
#define DIMINISHED_FIFTH    VERMINDERDE_KWINT   // 6
#define PERFECT_FIFTH       REINE_KWINT         // 7
#define AUGMENTED_FIFTH     KLEINE_SEXT         // 8
#define MINOR_SIXTH         KLEINE_SEXT         // 8
#define MAJOR_SIXTH         GROTE_SEXT          // 9
#define AUGMENTED_SIXTH     KLEINE_SEPTIEM      // 10
#define MINOR_SEVENTH       KLEINE_SEPTIEM      // 10
#define MAJOR_SEVENTH       GROTE_SEPTIEM       // 11
#define PERFECT_OCTAVE      OCTAAF              // 12


enum scaleKinds {
	CHROMATIC,
	OCTATONIC,
	DOMINANT_DIMINISHED,
	DIMINISHED,
	MAJOR, 
	MINOR,
	MELODIC_MINOR,
	HARMONIC_MINOR,
	GYPSY,
	SYMETRICAL,
	ENIGMATIC,
	ARABIAN,
	HUNGARIAN,
	WHOLE_TONE,
	AUGMENTED,
	BLUES_MAJOR,
	BLUES_MINOR,
	PENTATONIC,
	MINOR_PENTATONIC
};


/** Scale is a musical scale class 
 * @author Jan-Willem Smaal <usenet@gispen.org> 
 */ 
class Scale {
	public:
		// Constructor
        Scale(enum scaleKinds kindOfScale,
              uint8_t modeOf);
		
        // These setters change the object.
        bool SetMode(uint8_t modeOf);
		bool SetScale(enum scaleKinds kindOfScale);
        
        enum scaleKinds scale;
        std::string scaleName;
        std::string modeName;
		uint8_t notes; 
		uint8_t mode;
    
        // Max number of modes starting with 0 == first mode
    	uint8_t modes;
    	// These don't modify the Object
        const std::string Text(uint8_t rootnote,
                               bool flats);
		static const std::string NoteToText(uint8_t midinote,
                                     bool flats,
                                     bool showoctave);
	//private:
		uint8_t *ptrToScale; 
};

/////////////////////////////////////////////////////

/** Chord implements chords and inversions
  */
class Chord {
    public:
        enum chordKinds {
            POWER,
            BASIC,
            SEVENTH,
            NINE,
            ELEVEN,
            THIRTEEN,
            SUS4
        };
        // Basic chord
        Chord(Scale *scl,
              chordKinds kindOfChord,
              uint8_t rootnote);
        // Slash Chords have a different
        // bassnote from the rootnote
        Chord(Scale *scl,
              chordKinds,
              uint8_t rootnote,
              uint8_t bassnote);
        // Invert the chord leaving the bassnote intact
        void Invert(unsigned int);
        // Return a text representation of the chord
        const std::string Text(bool flats);
    private:
        Scale *scale;
        uint8_t notes[3];
        uint8_t rootnote;
        uint8_t bassnote;
};


/* End of header file  */ 
#endif 
	
