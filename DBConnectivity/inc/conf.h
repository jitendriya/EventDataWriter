using namespace log4cpp
{
log4cpp.rootCategory =DEBUG,category
log4cpp.appender.category = org.apache.log4cpp.RollingFileAppender
log4cpp.apeender.category.filename=category.log
log4cpp.appender.category.pattern=Date
log4cpp.appender.category.layout= org.apache.log4cpp.PatternLayout 
log4cpp.apeender.category.setConversionPattern=%d [%thread]-%5level %logger [%property{NDC}]-%message%newline

};
