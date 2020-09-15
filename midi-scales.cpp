/**
 * @file midi-scales.cpp
 * @author Jan-Willem Smaal <usenet@gispen.org> 
 * @date 3/9/2020 
 * @copyright APACHE 2.0
 */
#define JWS_DEBUG 1
#ifdef JWS_DEBUG 
#include <stdio.h>
#endif 

#include <string>
#include <iostream>
using namespace std;

#include "midi-scales.hpp"

/* 
 * This is just here to trace 'FACADE' in the flash 
 */
 uint8_t  facade[3]  = {
    0xfa,0xca,0xde
};


/*
 * Scales are listed below as arrays of
 * uint8_t indicating the either a 1/2 step as 1
 * or a whole step as 2.
 * minor 3'rd as 3
 */
/*
 * CHROMATIC Scale 12 note
 */
 uint8_t  chromatic[12]  = {
    1,1,1,1,1,1,1,1,1,1,1,1,
};

/*
 * OCTATONIC 8 notes (of course)
 */
 uint8_t  octatonic[2][8]  = {
    {1,2,1,2,1,2,1,2},
    {2,1,2,1,2,1,2,1}
};

/*
 * Dominant Diminished (Dom13, b9,#9, b5)   8 note scale
 * same as "first mode of OCTATONIC" see above
 */
 uint8_t  dominant_diminished[8]  = {
    1,2,1,2,1,2,1,2
};

/*
 * Diminished (Dim7, Maj/b9)  8 note scale
 * same as "second mode of OCTATONIC" see above
 */
 uint8_t  diminished[8]  = {
    2,1,2,1,2,1,2,1
};


/*
 * HEPTATONIC scales used by the
 * majority of western music
 */

/*
 * MAJOR Scale modes  7 notes
 */
/* Be aware when putting these things in ORY 
 * we need a MACRO to access them e.g. like below
 * uint8_t (*scale)[7] = pgm_read_ptr(&major[0]);  
 */
 uint8_t major_s[7][7]  = {
    {2,2,1,2,2,2,1}, // IONIAN
    {2,1,2,2,2,1,2}, // DORIAN
    {1,2,2,2,1,2,2}, // PHRYGIAN
    {2,2,2,1,2,2,1}, // LYDIAN
    {2,2,1,2,2,1,2}, // MIXOLYDIAN
    {2,1,2,2,1,2,2}, // AEOLIAN
    {1,2,2,1,2,2,2}  // LOCRIAN
};	

/*
 * MINOR Scale modes  7 notes
 */
 uint8_t  minor_s[7][7]  = {
    {2,1,2,2,1,2,2}, // AEOLIAN
    {1,2,2,1,2,2,2}, // LOCRIAN
    {2,2,1,2,2,2,1}, // IONIAN
    {2,1,2,2,2,1,2}, // DORIAN
    {1,2,2,2,1,2,2}, // PHRYGIAN
    {2,2,2,1,2,2,1}, // LYDIAN
    {2,2,1,2,2,1,2} // MIXOLYDIAN
};

/*
 * MELODIC MINOR Scale modes  7 notes
 */
 uint8_t  melodic_minor[7][7]  = {
    {2,1,2,2,2,2,1}, // Melodic minor     (minor major7)
    {1,2,2,2,2,1,2}, // DORIAN b2         (minor7 sus4 b9)
    {2,2,2,2,1,2,1}, // LYDIAN augmented  (major7 #4 #5)
    {2,2,2,1,2,1,2}, // MIXOLYDIAN #11    (dominant7 b5)
    {2,2,1,2,1,2,2}, // MIXOLYDIAN b6     (dominant7 b6)
    {2,1,2,1,2,2,2}, // LOCRIAN natural 9 (minor9 b6)
    {1,2,1,2,2,2,2}  // Altered Dominant  (dominant7, #9, b5, #5)
};

/*
 * HARMONIC MINOR Scale modes  7 notes
 */
 uint8_t  harmonic_minor[7][7]  = {
    {2,1,2,2,1,3,1}, // Harmonic minor    (minor major7)
    {1,2,2,1,3,1,2}, // LOCRIAN Nat.6     (minor7 b5)
    {2,2,1,3,1,2,1}, // IONIAN Augmented  (major7 sus4, #5)
    {2,1,3,1,2,1,2}, // DORIAN #11        (minor7 #11)
    {1,3,1,2,1,2,2}, // PHRYGIAN major    (dominant7 sus4, b9, #5
    {3,1,2,1,2,2,1}, // LYDIAN #9         (major7 #9,#11)
    {1,2,1,2,2,1,3} // ALTERED DOM bb7   (dim7)
};

/*
 * Gypsy scale
 */
 uint8_t  gypsy[7]   = 	{
    2,1,3,1,1,3,1
};


/*
 * Symetrical scale
 */
 uint8_t  symetrical[7]  = {
    1,2,2,3,1,1,2
};

/*
 * Enigmatic scale
 */
 uint8_t  enigmatic[7]  = {
    1,3,2,2,2,1,1
};

/*
 * Arabian scale
 */
 uint8_t  arabian[7]  = {
    2,2,1,1,2,2,2
};

/*
 * Hungarian scale
 */
 uint8_t  hungarian[7]  = {
    3,1,2,1,2,1,2
};

/*
 * Whole tone (Dom7 #5, b6)   6 note scale
 */
 uint8_t  whole_tone[6]  = {
    2,2,2,2,2,2
};
//  uint8_t *hexatonic  = whole_tone;

	
/*
 * Augmented (Aug)   6 note scale
 * (two modes? how does one call this second one then)
 */
 uint8_t  augmented[2][6]  = {
    {3,1,3,1,3,1},
    {1,3,1,3,1,3}
};

/*
 * Blues major  6 note scale
 */
 uint8_t  blues_major[6]  = {
    2,1,1,3,2,3
};

/*
 * Blues minor  6 note scale
 * not sure if these are called "modes"
 */
 uint8_t  blues_minor[6][6]  = {
    {3,2,1,1,3,2},
    {2,1,1,3,2,3},      // Same as blues major scale
    {1,1,3,2,3,2},
    {1,3,2,3,2,1},
    {3,2,3,2,1,1},
    {2,3,2,1,1,3}
};

/*
 * Major Pentatonic  5 note scale
 */
 uint8_t  pentatonic[5]  = {
    2,2,3,2,3
};

/*
 * Minor Pentatonic  5 note scale
 */
 uint8_t  minor_pentatonic[5]  = {
    3,2,2,3,2
};

/*
 * Evey embedded program needs a
 * a piece of dead beef
 */
 uint8_t  deadbeef[4]  = {
    0xde,0xad,0xbe,0xef,
};


struct MidiNotes 
{
	uint8_t note; 
	char name[3];
};


//-----------------------------------------------------------------

/** Scales implements a number of musical scales
 *
 * 
 * @author: Jan-Willem Smaal <usenet@gispen.org> 
 */ 

// Constructors 
Scale::Scale(enum scaleKinds kindOfScale, uint8_t modeOf) {
	int i; 
	int tmp; 

	// Most scales are 7 notes (heptatonic) 
	// unless specifically changed for some less common scales 
	// below  
	notes = 7;
	//some exotic scales have just one mode. 
	modes = 0;
	// Init the class with the mode given. 
	//mode = modeOf;
 
    SetMode(modeOf);
    SetScale(kindOfScale);
};


bool Scale::SetMode(uint8_t modeOf) {
    // TODO: check if the argument is in range
    Scale::mode = modeOf;
    SetScale(Scale::scale);
    return true;
}


bool Scale::SetScale(enum scaleKinds kindOfScale) {
    int i;
    int tmp;

    // Most scales are 7 notes (heptatonic)
    // unless specifically changed for some less common scales
    // below
    notes = 7;
    //some exotic scales have just one mode.
    modes = 0;
    
    switch(kindOfScale) {
        case MAJOR:
            ptrToScale = &major_s[mode][0];
            modes = 7;
            scale = MAJOR;
            scaleName = "Major";
            switch (Scale::mode) {
                case 0:
                    modeName = "Ionian";
                    break;
                case 1:
                    modeName = "Dorian";
                    break;
                case 2:
                    modeName = "Phrygian";
                    break;
                case 3:
                    modeName = "Lydian";
                    break;
                case 4:
                    modeName = "Mixolydian";
                    break;
                case 5:
                    modeName = "Aeolian";
                    break;
                case 6:
                    modeName = "Locrian";
                    break;
                default:
                    modeName = "?";
                    break;
                    
            }
            break;
        case MINOR:
            ptrToScale = &minor_s[mode][0];
            modes = 7;
            scale = MINOR;
            scaleName = "Minor";
            switch (Scale::mode) {
                case 0:
                    modeName = "Aeolian";
                    break;
                case 1:
                    modeName = "Locrian";
                    break;
                case 2:
                    modeName = "Ionian";
                    break;
                case 3:
                    modeName = "Dorian";
                    break;
                case 4:
                    modeName = "Phrygian";
                    break;
                case 5:
                    modeName = "Lydian";
                    break;
                case 6:
                    modeName = "Mixolydian";
                    break;
                default:
                    modeName = "?";
                    break;
            }
            break;
        case MELODIC_MINOR:
            ptrToScale = &melodic_minor[mode][0];
            modes = 7;
            scale = MELODIC_MINOR;
            scaleName = "Melodic minor";
            switch (Scale::mode) {
                case 0:
                    modeName = "Melodic minor";
                    break;
                case 1:
                    modeName = "Dorian b2";
                    break;
                case 2:
                    modeName = "Lydian augmented";
                    break;
                case 3:
                    modeName = "Mixolydian #11";
                    break;
                case 4:
                    modeName = "Mixolydian b6";
                    break;
                case 5:
                    modeName = "Locrian natural9";
                    break;
                case 6:
                    modeName = "Altered Dominant";
                    break;
                default:
                    modeName = "?";
                    break;
            }
            
            break;
        case HARMONIC_MINOR:
            ptrToScale = &harmonic_minor[mode][0];
            modes = 7;
            scale = HARMONIC_MINOR;
            scaleName = "Harmonic minor";
            switch (Scale::mode) {
                case 0:
                    modeName = "Harmonic minor";
                    break;
                case 1:
                    modeName = "Locrian natural6";
                    break;
                case 2:
                    modeName = "Ionian augmented";
                    break;
                case 3:
                    modeName = "Dorian #11";
                    break;
                case 4:
                    modeName = "Phrygian major";
                    break;
                case 5:
                    modeName = "Lydian #9";
                    break;
                case 6:
                    modeName = "Altered dominant bb7";
                    break;
                default:
                    modeName = "?";
                    break;
            }
            break;
        // No modes in these ones
        case GYPSY:
            notes = 7;
            ptrToScale = &gypsy[0];
            scale = GYPSY;
            scaleName = "Gypsy";
            break;
        case SYMETRICAL:
            ptrToScale = &symetrical[0];
            scale = SYMETRICAL;
            scaleName = "Symetrical";
            break;
        case ENIGMATIC:
            ptrToScale = &enigmatic[0];
            scale = ENIGMATIC;
            scaleName = "Enigmatic";
            break;
        case ARABIAN:
            ptrToScale = &arabian[0];
            scale = ARABIAN;
            scaleName = "Arabian";
            break;
        case HUNGARIAN:
            ptrToScale = &hungarian[0];
            scale = HUNGARIAN;
            scaleName = "Hungarian";
            break;
        // These scales have 6 notes
        case WHOLE_TONE:
            notes = 6;
            ptrToScale = &whole_tone[0];
            scale = WHOLE_TONE;
            scaleName = "Whole tone";
            break;
        // Augmented has two modes not sure what to call
        // the second one
        case AUGMENTED:
            notes = 6;
            modes = 2;
            ptrToScale = &augmented[mode][0];
            scale = AUGMENTED;
            scaleName = "Augmented";
            break;
        case BLUES_MAJOR:
            notes = 6;
            ptrToScale = &blues_major[0];
            scale = BLUES_MAJOR;
            scaleName = "Blues major";
            break;
        // Blues minor has modes I guess...
        case BLUES_MINOR:
            notes = 6;
            modes = 6;
            if (mode >= 6){
                mode = 0;
            }
            ptrToScale = &blues_minor[mode][0];
            scale = BLUES_MINOR;
            scaleName = "Blues minor";
            break;
        // These scales have 5 notes
        case PENTATONIC:
            notes = 5;
            ptrToScale = &pentatonic[0];
            scale = PENTATONIC;
            scaleName = "Pentatonic";
            break;
        case MINOR_PENTATONIC:
            notes = 5;
            ptrToScale = &minor_pentatonic[0];
            scale = MINOR_PENTATONIC;
            scaleName = "Minor Pentatonic";
            break;
        // 12 Notes is the max (in our Western system)
        case CHROMATIC:
            notes = 12;
            ptrToScale = &chromatic[0];
            scale = CHROMATIC;
            scaleName = "Chromatic";
            break;
        // 8 note keys
        case OCTATONIC:
            notes = 8;
            modes = 2;
            if (mode >= 2) {
                mode = 0;
            }
            ptrToScale = &octatonic[mode][0];
            scale = OCTATONIC;
            scaleName = "Octatonic";
            break;
        case DOMINANT_DIMINISHED:
            notes = 8;
            // ptrToScale = &dominant_diminished[0];
            // Dominant dim is the same as the first mode of the
            // octatonic so we could also do the below
            ptrToScale = &octatonic[0][0];
            scale = DOMINANT_DIMINISHED;
            scaleName = "Dominant Diminished";
            break;
        case DIMINISHED:
            notes = 8;
            // ptrToScale = &dominant_diminished[0];
            // dim is the same as the second mode of the
            // octatonic so we could also do the below
            ptrToScale = &octatonic[1][0];
            scale = DIMINISHED;
            scaleName = "Diminished";
            break;
        default:
            mode = 0;
            notes = 0;
            break;
    }
    return true;
}


/** Print out text representation of the scale starting at rootnote
  */
const std::string Scale::Text(uint8_t rootnote, bool flats) 
{
	int i;
	uint8_t tmp; 	
	std::string str; 

	tmp = rootnote; 
	if(notes != 0) {
		for(i = 0; i < (unsigned int)Scale::notes ; i++){
			str = str + NoteToText(tmp, flats, false) + " ", 
			tmp  = tmp + (unsigned int)*(ptrToScale + i); 
		}
	}
	return str; 
}


/** Simply convert MIDI notename to a note (either using flats or sharps
 */
const std::string Scale::NoteToText(uint8_t midinote,
                                    bool flats,
                                    bool showoctave)
{
	int octave;
	uint8_t note;
	std::string strng; 
  
	// For MIDI note 0 is written down as "C-2" hence the -2 below	
	octave = (midinote / 12) - 2; 
	note = midinote - ((octave + 2) * 12); 

	if(flats) {
		switch(note) {
			case 0:
				strng = "C";
				break;	
			case 1:
				strng = "Db";
				break;	
			case 2:
				strng = "D";
				break;	
			case 3:
				strng = "Eb";
				break;	
			case 4:
				strng = "E";
				break;	
			case 5:
				strng = "F";
				break;	
			case 6:
				strng = "Gb";
				break;	
			case 7:
				strng = "G";
				break;	
			case 8:
				strng = "Ab";
				break;	
			case 9:
				strng = "A";
				break;	
			case 10:
				strng = "Bb";
				break;	
			case 11:
				strng = "B";
				break;	
			default:
				strng = "!!";
				break;
		}
	}
	else {
		switch(note) {
			case 0:
				strng = "C";
				break;	
			case 1:
				strng = "C#";
				break;	
			case 2:
				strng = "D";
				break;	
			case 3:
				strng = "D#";
				break;	
			case 4:
				strng = "E";
				break;	
			case 5:
				strng = "F";
				break;	
			case 6:
				strng = "F#";
				break;	
			case 7:
				strng = "G";
				break;	
			case 8:
				strng = "G#";
				break;	
			case 9:
				strng = "A";
				break;	
			case 10:
				strng = "A#";
				break;	
			case 11:
				strng = "B";
				break;	
			default:
				strng = "!!";
				break;
		}
	}

	//octave = (midinote / 12) - 1; 
	if (showoctave) {
		strng = strng + std::to_string(octave);
	}
	return strng;
}


//-----------------------------------------------------------------

/** Chord implements chords and inversions
  */
Chord::Chord(Scale *scl,
             chordKinds KindOfChord,
             uint8_t rootnote) {
    int i, j;
    uint8_t nte = rootnote;
    
    Chord::rootnote = rootnote;
    Chord::bassnote = rootnote;
    scale = scl;
    
    // Basic triad is the only one implemented till now.
    for(i = 0; i < (unsigned int)scl->notes ; i++){
        switch(i) {
            case 0:
                notes[0] = nte;
                break;
            case 2:
                notes[1] = nte;
                break;
            case 4:
                notes[2] = nte;
                break;
            default:
                break;
        }
        nte = nte + (unsigned int)*(scl->ptrToScale + i);
    }
};


const std::string Chord::Text(bool flats) {
    
    return "( " + Scale::NoteToText(notes[0], flats, false) + "," +
           Scale::NoteToText(notes[1], flats, false) + "," +
        Scale::NoteToText(notes[2], flats, false) + ")";
}

/* EOF */ 
