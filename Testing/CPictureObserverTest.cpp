/**
 * \file CPictureObserverTest.cpp
 *
 * \author Yiteng Zhang
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "PictureObserver.h"
#include "Picture.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace Testing
{
	class CPictureObserverMock : public CPictureObserver
	{
	public:
		CPictureObserverMock() : CPictureObserver() {}
		virtual void UpdateObserver() override { mUpdated = true; }
		bool mUpdated = false;
	};

	TEST_CLASS(CPictureObserverTest)
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

		TEST_METHOD(TestCPictureObserverConstruct)
		{
			CPictureObserverMock observer;
		}

		TEST_METHOD(TestCPictureObserverOneObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// And set it for the observer:
			observer.SetPicture(picture);

			picture->UpdateObservers();

			Assert::IsTrue(observer.mUpdated);

		}
		
		TEST_METHOD(TestCPictureObserverGetPicture)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// And set it for the observer:
			observer.SetPicture(picture);

			Assert::IsTrue(observer.GetPicture() == picture);

		}

		TEST_METHOD(TestCPictureObserverTwoObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			CPictureObserverMock observer2;

			// And set it for the observer:
			observer.SetPicture(picture);
			observer2.SetPicture(picture);


			picture->UpdateObservers();

			Assert::IsTrue(observer.mUpdated);

			Assert::IsTrue(observer2.mUpdated);

		}

		TEST_METHOD(TestCPictureObserverWithDestroy)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;


			// And set it for the observer:
			observer.SetPicture(picture);

			{
				CPictureObserverMock observer2;

				// And set it for the observer:
				observer2.SetPicture(picture);
			}

			picture->UpdateObservers();

			Assert::IsTrue(observer.mUpdated);
		}
		
	};
}