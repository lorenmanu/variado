from django.conf.urls import patterns, include, url
from pisos import views

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'grycosta.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),
        url(r'^$',views.index, name='index'),
	url(r'^buscador2',views.buscador2, name='buscador2'),
	url(r'^buscador', views.buscador, name='buscador'),
	url(r'contact', views.contact, name='contact'),
)

