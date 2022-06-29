# 做的全部队 日历 设计文档

VERSION: 0.2
DATE: 2022/06/26

期限：
- 6月27日：日历展示本体
- 6月29日：一切功能做好
- 6月30日：整合再提交

## 功能

- 日历展示-许浩哲
    - 调制QT本身就有的日历Widget
        - 不同的日历表现方法：
            - 每页一年
            - 每页一月
            - 每页一周
            - 每页一日
        - 其他设定
            - 周数（1-52）
            - 每周开始的日期：（1-7）
        
- 日历本体 - 邵果毅
    - 看看怎么把农历也放进去
    - 把假期放到日历里
    - 当年今日

- 实验报告 - 张旭


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
