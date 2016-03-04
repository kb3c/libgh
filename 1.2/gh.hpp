/* gh.hpp 
 * header for libgh C++ interface
 * 
 * Copyright(c) 2016, polarysekt
 */


#ifndef libghinc_obj_gh_hpp__
#  define libghinc_obj_gh_hpp__

#include <iostream>
#include <vector>

extern "C" {
#include "gh.h"
}

#ifndef NDEBUG
#  define dout std::cout
#else
#  define dout if(0) std::cout
#endif

namespace gh {

  class WINDOW { //: public IWINSTATE {
  public:
    
    WINDOW( RUNNABLE* pr = NULL ) {
      dout << ":++: %s( " << pr << " )\n";
      pw_ = ghWindowCreate();
      
    };
    
    virtual ~WINDOW() {
      ghWindowDestroy( pw_ );
      //setWindowRef( NULL );
    };

    bool init( ) {
      if( ghWindowInit( pw_ ) < 0 ) return false;
      return true;
    };

    void shutdown( ) {
      ghWindowShutdown( pw_ );
    };

    void hide() {
      ghWindowHide( pw_ );
    }
    
    void show( ) {
      ghWindowShow( pw_ );
    };
    
    unsigned int getBorderWidth() {
      return ghWindowGetBorderWidth( pw_ );
    }
    
    char* getCaption( ) {
      return ghWindowGetCaption( pw_ );
    }
    
    ghRET getExtent( unsigned int* w, unsigned int* ph ) {
	    return ghWindowGetExtent2i( pw_, w, h );
    }
    
    WINDOW* getParent( ) {
      return ghWindowGetParent( pw_ );
    }
    
    ghRET getPosition( int* x, int* y ) {
	  return ghWindowGetPosition2i( pw_, x, y );
    }
    
    int getWidth() {
      return ghWindowGetWidth( pw_ );
    }
    
    unsigned int getHeight() {
	return ghWindowGetHeight( pw_ );
    }
    
    int getX() {
      return ghWindowGetX( pw_ );
    }
    
    int getY() {
      return ghWindowGetY( pw_ );
    }
    
    ghRET setBorderWidth( unsigned int bw ) {
      return ghWindowSetBorderWidth( pw_, bw );
    }

    ghRET setCaption( const char* pszcap ) {
      return ghWindowSetCaption( pw_, pszcap );
    }

    ghRET setParent( WINDOW* pp ) {
      return ghWindowSetParent( pw_, pp->getWindowRef() );
    };

    ghRET setPosition( int x, int y ) {
      return ghWindowSetPosition( pw_, x, y );
    };
    
    ghRET setExtent( unsigned int w, unsigned int h ) {
      return ghWindowSetExtent( pw_, w, h );
    };
    
	ghWINDOW* getWindowRef( ) { 
      return pw_;
    }
    
  protected:
    ghRET setWindowRef( ghWINDOW* pw ) {

      if( pw ) {
	dout << "    == MODE: SET to ARG\n"; 
	clearWindowRef();
	dout << "    == SET new WindowRef...";
	pw_ = pw;
	dout << "[OK]\n";
      } else {
	  dout << "      == MODE: CLEAR WindowRef\n";
	  clearWindowRef();
      }
      
      return 0;
    }

  private:
    ghRUNNABLE*	pr_;
    ghWINDOW*	pw_;
    
    void clearWindowRef() {
      dout << "clearWindowRef() {\n";
      dout << "    == CHECK existing WindowRef\n";
      if( pw_ ) {
	dout << "  :: [YES] : " << pw_ << "\n";
	dout << "    == DESTROY EXISTING WindowRef\n";
	ghWindowDestroy( pw_ );	
      } else {
	dout << "  :: [NO ] : 0\n";
	pw_ = 0; /* set initial null */
      }      
      
      dout << "}\n";
      
    };
        
  };

  class RUNNABLE {
    public:
      RUNNABLE( int* pargc, char*** pargv ) {
	ghInit( pargc, pargv );
      };
      virtual ~RUNNABLE() {
	//ghShutdown();
      };

      virtual int run() {
	return ghRun();
      };
  };
  
  class APPLICATION: public RUNNABLE {
  public:
    APPLICATION( int* pargc, char*** pargv ) : RUNNABLE( pargc, pargv ) {
      
    }
    
    virtual ~APPLICATION() {

    }
  protected:
    
  };  
  
}

#endif
