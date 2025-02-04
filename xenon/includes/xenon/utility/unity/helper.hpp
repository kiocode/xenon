#pragma once

//#include <il2cpp_resolver/IL2CPP_Resolver.hpp>
//#include <il2cpp_resolver/Unity/API/Camera.hpp>
//#include <xenon/utility/vec2.hpp>
//
//namespace UnityHelper {
//	bool WorldToScreen(Unity::Vector3 world, Vec2& screen)
//	{
//		Unity::CCamera* CameraMain = Unity::Camera::GetMain();
//		if (!CameraMain) {
//			return false;
//		}
//
//		Unity::Vector3 buffer = CameraMain->CallMethodSafe<Unity::Vector3>("WorldToScreenPoint", world, Unity::eye::mono);
//
//		if (buffer.x > Variables::System::ScreenSize.x || buffer.y > Variables::System::ScreenSize.y || buffer.x < 0 || buffer.y < 0 || buffer.z < 0)
//		{
//			return false;
//		}
//
//		if (buffer.z > 0.0f)
//		{
//			screen = Vec2(buffer.x, Variables::System::ScreenSize.y - buffer.y);
//		}
//
//		if (screen.x > 0 || screen.y > 0)
//		{
//			return true;
//		}
//	}
//}