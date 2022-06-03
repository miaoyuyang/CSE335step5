#include "pch.h"
#include "CppUnitTest.h"
#include "Actor.h"
using namespace Gdiplus;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	class CActorMock : public CActor
	{
	public:
		CActorMock(const std::wstring& name) : CActor(name) {}

		
	};
	TEST_CLASS(CActorTest)
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

		TEST_METHOD(TestCActorConstructor)
		{
			CActor actor(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), actor.GetName());
		}

		TEST_METHOD(TestCActorEnabled)
		{
			CActor actor(L"Harold");
			Assert::IsTrue(actor.IsEnabled());
			actor.SetEnabled(false);
			Assert::IsFalse(actor.IsEnabled());
		}

		TEST_METHOD(TestCActorClickable)
		{
			CActor actor(L"Harold");
			Assert::IsTrue(actor.IsClickable());
			actor.SetClickable(false);
			Assert::IsFalse(actor.IsClickable());
		}

		TEST_METHOD(TestCActorPosition) 
		{
			CActor actor(L"Harold");
			Assert::AreEqual(0, actor.GetPosition().X);
			Assert::AreEqual(0, actor.GetPosition().Y);
			actor.SetPosition(Gdiplus::Point(1, 2));
			Assert::AreEqual(1, actor.GetPosition().X);
			Assert::AreEqual(2, actor.GetPosition().Y);

		}

	};
}