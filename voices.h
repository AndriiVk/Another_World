#ifndef VOICES_H
#define VOICES_H

#include <QSound>

class Voices{
public:
    Voices(){}

    void get_Hready  ()  { QSound::play("Hready.wav");   }
    void get_Hhelp1  ()  { QSound::play("Hhelp1.wav");   }
    void get_Hhelp2  ()  { QSound::play("Hhelp2.wav");   }
    void get_Hdead   ()  { QSound::play("Hdead.wav");    }
    void get_Hrescue ()  { QSound::play("Hrescue.wav");  }
    void get_Eready  ()  { QSound::play("Eready.wav");   }
    void get_Pkwhat1 ()  { QSound::play("Pkwhat1.wav");  }
    void get_OReady  ()  { QSound::play("OReady.wav");   }
    void get_Ohelp1  ()  { QSound::play("Ohelp1.wav");   }
    void get_Ohelp2  ()  { QSound::play("Ohelp2.wav");   }
    void get_Odead   ()  { QSound::play("Odead.wav");    }
    void get_Orescue ()  { QSound::play("Orescue.wav");  }
    void get_Trready ()  { QSound::play("Trready.wav");  }
    void get_Ogready ()  { QSound::play("Ogready.wav");  }
    void get_Sword1  ()  { QSound::play("Sword1.wav");   }
    void get_Bowfire ()  { QSound::play("Bowfire.wav");  }
    void get_Bowhit  ()  { QSound::play("Bowhit.wav");   }
    void get_Fist    ()  { QSound::play("Fist.wav");     }
    void get_Axe     ()  { QSound::play("Axe.wav");      }
    void get_Catapult()  { QSound::play("Catapult.wav"); }
    void get_Catyessr()  { QSound::play("Catyessr.wav"); }
    void get_Explode ()  { QSound::play("Explode.wav");  }
    void get_Bldexpl2()  { QSound::play("Bldexpl2.wav"); }
    void get_Exorcism()  { QSound::play("Exorcism.wav"); }
    void get_Iokilrog()  { QSound::play("Iokilrog.wav"); }
};

#endif // VOICES_H
