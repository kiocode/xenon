#include <xenon/components/services/notification_service.hpp>

void CNotificationService::RenderNotifications() {

	for (Notification& notification : m_vQueuedNotifications) {
		notification.Render(m_imFont, m_imLogo);// , m_imLogoBigger);
	}

}

void CNotificationService::RemoveQueuedNotification(int nIndex) {

	m_vQueuedNotifications.erase(m_vQueuedNotifications.begin() + nIndex);

}

void CNotificationService::Notify(std::string title, std::string message) {

	if (m_vQueuedNotifications.size() > 5) {
		m_vQueuedNotifications.erase(m_vQueuedNotifications.begin());
	}

	Notification notification = Notification(static_cast<int>(m_vQueuedNotifications.size()), title, message);
	m_vQueuedNotifications.push_back(notification);
}