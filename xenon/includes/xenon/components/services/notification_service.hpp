#pragma once

#include <vector>

#include <xenon/models/notification.hpp>

#include <xenon/components/component.hpp>

/**
 * @class NotificationService
 * @brief A service for managing and rendering in-game notifications.
 *
 * The NotificationService class handles the creation, display, and removal of
 * notifications within the game. Notifications can be queued and rendered
 * using specific fonts. It also supports customizing font rendering.
 */
class NotificationService : public CComponent {
public:

    /**
     * @brief Renders all queued notifications.
     *
     * This method renders the notifications that have been queued to be displayed
     * on the screen. It should be called every frame to ensure that the notifications
     * are displayed at the correct time.
     */
    void RenderNotifications();

    /**
     * @brief Removes a queued notification by its index.
     * @param nIndex The index of the notification to remove.
     *
     * This function removes a notification from the queue, effectively stopping
     * it from being rendered. The index is used to identify which notification
     * to remove.
     */
    void RemoveQueuedNotification(int nIndex);

    /**
     * @brief Queues a new notification.
     * @param title The title of the notification.
     * @param message The message content of the notification.
     *
     * This function adds a notification to the queue to be rendered later.
     * Notifications include both a title and a message.
     */
    void Notify(std::string title, std::string message);

    /**
     * @brief Sets the fonts for rendering notifications.
     * @param imFont The font used for regular notification text.
     * @param imLogo The font used for logos or special text in notifications.
     *
     * This function sets the fonts to be used when rendering notifications.
     * It allows customization of how notifications appear on screen.
     */
    void SetFonts(ImFont* imFont, ImFont* imLogo) {
        m_imFont = imFont;
        m_imLogo = imLogo;
    }

private:
    ImFont* m_imFont = nullptr; ///< The font used for regular notification text.
    ImFont* m_imLogo = nullptr; ///< The font used for logos or special text in notifications.

    std::vector<Notification> m_vQueuedNotifications; ///< A queue of notifications to be rendered.
};
