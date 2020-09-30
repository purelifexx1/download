import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { MenuComponent } from './Components/Blocks/Menu/menu.component';
import { SliderComponent } from './Components/Blocks/Slider/slider.component';
import { UserComponent } from './Components/Blocks/Users/user.component'
import { CategoryComponent } from './Components/Blocks/Categories/category.component'

import {CateComponent } from './Components/Pages/Cate/cate.component'
import {HomeComponent } from './Components/Pages/Home/home.component'
import {DetailComponent } from './Components/Pages/Detail/detail.component'

  import { from } from 'rxjs';
@NgModule({
  declarations: [
    AppComponent,
    MenuComponent,
    SliderComponent,
    UserComponent,
    CategoryComponent,
    CateComponent,
    HomeComponent,
    DetailComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
