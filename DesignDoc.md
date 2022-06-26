# 做的全部队 日历 设计文档

VERSION: 0.2
DATE: 2022/06/26

## 功能

- 天气
- 当年今日


- 日历展示-张旭
    - 调制QT本身就有的日历Widget
        - 不同的日历表现方法：
            - 每页一年
            - 每页一月
            - 每页一周
            - 每页一日
        - 其他设定
            - 周数（1-52）
            - 每周开始的日期：（1-7）
    - 日程
        - 按日历可以添加按的那天的日程
        
- 日历本体 - 邵果毅
    - 看看怎么把农历也放进去
    - 把假期放到日历里

- 日程管理 - 许浩哲
    - 日程
        - 把日程管理里调出的日程放进日历
    - 日程类别 + 类别颜色
    - 添加日程的API端口
        - 日程名称
        - 日程开始时间
        - 日程结束时间
        - 重复日程设计
            - 每天
            - 每周
            - 每月
            - 每年
    - iCalendar
        - 调出日程
        - 调入日程
        
    - API：(tentative)
        - enum class RepeatMode
            - none
            - daily
            - weekly
            - monthly
            - yearly
        - eventID NewEvent(
            const QString& name, 
            const QDateTime& start, 
            const QDateTime& end,
            const QColor& color, 
            const QString& desc="",
            const RepeatMode r=none
            )
            - Creates new event, returns the eventID
        - event DelEvent(
            const eventID& id, 
            bool deleteRepeating
            )
            - Deletes event with eventID id and returns event details

## Features
- Calendar Display
    - Calendar Views
        - Year
        - Monthly
        - Weekly
        - Daily (Hour by Hour)
    - Event Display
        - Display the Events from the Event Manager
    - Settings
        - Show Week Number
        - Start of Week: Monday/Sunday
- Calendar
    - Holidays
    - Gregorian
    - Lunar
    - From 1970 - 2105
    - Holidays
- Event Manager
    - Event Categories + Colors
    - Add Events to Calendar by clicking on time
        - Meeting
        - Time
        - Repeats
    - iCalendar
        - VCALENDAR
        - VEVENT
