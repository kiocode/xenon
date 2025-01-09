#pragma once

#include <vector>

#include <xenon/models/notification.hpp>

class NotificationService {
public:
	void RenderNotifications();
	void RemoveQueuedNotification(int nIndex);
	void Push(std::string title, std::string message);

	void SetFonts(ImFont* imFont, ImFont* imLogo, ImFont* imLogoBigger) {
		m_imFont = imFont;
		m_imLogo = imLogo;
		m_imLogoBigger = imLogoBigger;
	}
private:
	ImFont* m_imFont = nullptr;
	ImFont* m_imLogo = nullptr;
	ImFont* m_imLogoBigger = nullptr;

	std::vector<Notification> m_vQueuedNotifications;
};