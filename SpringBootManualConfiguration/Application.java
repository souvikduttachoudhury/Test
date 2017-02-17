package com.lister.Project;


import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.dao.PersistenceExceptionTranslationAutoConfiguration;
import org.springframework.boot.autoconfigure.jdbc.DataSourceAutoConfiguration;
import org.springframework.boot.autoconfigure.jdbc.DataSourceTransactionManagerAutoConfiguration;
import org.springframework.boot.autoconfigure.orm.jpa.HibernateJpaAutoConfiguration;
import org.springframework.boot.autoconfigure.thymeleaf.ThymeleafAutoConfiguration;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.boot.context.embedded.EmbeddedWebApplicationContext;
import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.boot.web.support.SpringBootServletInitializer;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.ComponentScan;

import com.lister.Project.config.MvcConfiguration;

@SuppressWarnings("unused")
@ComponentScan(basePackages={"com.lister.Project.config,com.lister.Project.controller,com.lister.Project.domain,com.lister.Project.service,com.lister.Project.dao"})
@EnableConfigurationProperties(MvcConfiguration.class)
public class Application extends  EmbeddedWebApplicationContext{

	    public static void main(final String[] args) {
	    	ApplicationContext ctx =SpringApplication.run(Application.class, args);
	    }
}

