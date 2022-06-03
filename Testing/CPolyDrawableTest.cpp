#include "pch.h"
#include "CppUnitTest.h"
#include "PolyDrawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;

namespace Testing
{
    
    TEST_CLASS(CPolyDrawableTest)
    {
    public:

        TEST_METHOD_INITIALIZE(methodName)
        {
            extern wchar_t g_dir[];
            ::SetCurrentDirectory(g_dir);
        }

        TEST_METHOD(TestNothing)
        {
            // This is an empty test just to ensure the system is working
        }

        TEST_METHOD(TestCPolyDrawableConstructor)
        {
            CPolyDrawable polydrawable(L"Harold");
            Assert::AreEqual(std::wstring(L"Harold"), polydrawable.GetName());
        }

        TEST_METHOD(TestCPolyDrawableColor)
        {
            CPolyDrawable polydrawable(L"Harold");
            Color Black = Color::Black;
            Assert::AreEqual(Black.GetA(), polydrawable.GetColor().GetA());
            Assert::AreEqual(Black.GetR(), polydrawable.GetColor().GetR());
            Assert::AreEqual(Black.GetG(), polydrawable.GetColor().GetG());
            Assert::AreEqual(Black.GetB(), polydrawable.GetColor().GetB());

            Color Blue = Color::Blue;
            polydrawable.SetColor(Blue);
            Assert::AreEqual(Blue.GetA(), polydrawable.GetColor().GetA());
            Assert::AreEqual(Blue.GetR(), polydrawable.GetColor().GetR());
            Assert::AreEqual(Blue.GetG(), polydrawable.GetColor().GetG());
            Assert::AreEqual(Blue.GetB(), polydrawable.GetColor().GetB());


        }

    };
}