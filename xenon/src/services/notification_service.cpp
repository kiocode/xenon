#include <xenon/services/notification_service.hpp>

void NotificationService::RenderNotifications() {

	for (Notification& notification : m_vQueuedNotifications) {
		notification.Render(m_imFont, m_imLogo, m_imLogoBigger);
	}

}

void NotificationService::RemoveQueuedNotification(int nIndex) {

	m_vQueuedNotifications.erase(m_vQueuedNotifications.begin() + nIndex);

}

void NotificationService::Notify(std::string title, std::string message) {

	if (m_vQueuedNotifications.size() > 5) {
		m_vQueuedNotifications.erase(m_vQueuedNotifications.begin());
	}

	Notification notification = Notification(m_vQueuedNotifications.size(), title, message);
	m_vQueuedNotifications.push_back(notification);
}