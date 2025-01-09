#pragma once

#include <vector>

#include <xenon/models/notification.hpp>

class NotificationService {
public:

	void RenderNotifications();
	void RemoveQueuedNotification(int nIndex);
	void Notify(std::string title, std::string message);

	void SetFonts(ImFont* imFont, ImFont* imLogo) {
		m_imFont = imFont;
		m_imLogo = imLogo;
	}
private:
	ImFont* m_imFont = nullptr;
	ImFont* m_imLogo = nullptr;
	//ImFont* m_imLogoBigger = nullptr;

	std::vector<Notification> m_vQueuedNotifications;
};