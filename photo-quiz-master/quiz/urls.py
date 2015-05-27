from django.conf.urls import patterns, include, url
from quiz import views

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'grycosta.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),
    url(r'^$',views.index,name='index'),
    url(r'^add',views.add,name='add'),
    url(r'^help',views.help,name='help'),
    url(r'^juego',views.juego,name='juego'),
    url(r'^register',views.RegistrationView,name='register'),
    url(r'^contact',views.contact,name='contact'),
    url(r'^ranking',views.ranking,name='ranking'),    
)
urlpatterns += patterns('django.contrib.auth.views',
    url(r'^login/$', 'login', {'template_name': 'login.html'}, name='mysite_login'),
    url(r'^logout/$', 'logout', {'next_page': '/quiz/'}, name='mysite_logout'),
    
)

