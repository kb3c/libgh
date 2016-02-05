#include <iostream>

extern "C" {
#include "gh.h"
}

#ifndef NDEBUG
#  define dout std::cout
#else
#  define dout if(0) std::cout
#endif

namespace gh {

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
    
  };
  
  class WINDOW { //: public IWINSTATE {
  public:	
    WINDOW( RUNNABLE* pr = NULL ) {
      dout << ":++: %s( " << pr << " )\n";
      pw_ = ghWindowCreate();
      
    };
    ~WINDOW() {
      ghWindowDestroy( pw_ );
      //setWindowRef( NULL );
    };

    virtual bool init( ) {
      return ghWindowInit( pw_ );
    };

    void shutdown( ) {
      ghWindowShutdown( pw_ );
    };

    void show( ) {
      ghWindowShow( pw_ );
    };
	
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

}

