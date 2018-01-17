//! \example tutorial-draw-line.cpp
#include <visp3/gui/vpDisplayGDI.h>
#include <visp3/gui/vpDisplayX.h>

int main()
{
  vpImage<unsigned char> I(2160, 3840, 128);

  try {

#if defined(VISP_HAVE_X11)
    vpDisplayX d(I, vpDisplay::SCALE_AUTO);
#elif defined(VISP_HAVE_GDI)
    vpDisplayGDI d(I, vpDisplay::SCALE_AUTO);
#endif
    
    vpDisplay::setTitle(I, "My image");
    vpDisplay::display(I);
    vpDisplay::displayLine(I, I.getHeight() / 4, I.getWidth() / 4, (3 * I.getHeight() ) / 4, (3 * I.getWidth() ) / 4, vpColor::red, 10);
    vpDisplay::flush(I);
    std::cout << "A click to quit..." << std::endl;
    vpDisplay::getClick(I);
  } catch (const vpException &e) {
    std::cout << "Catch an exception: " << e.getMessage() << std::endl;
  }
}