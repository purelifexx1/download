import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import {approutingmodules} from './app-rounting'

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { MenuComponent } from './Components/Blocks/Menu/menu.component';
import { SliderComponent } from './Components/Blocks/Slider/slider.component';
import { UserComponent } from './Components/Blocks/Users/user.component'
import { CategoryComponent } from './Components/Blocks/Categories/category.component'


  import { from } from 'rxjs';
@NgModule({
  declarations: [
    AppComponent,
    MenuComponent,
    SliderComponent,
    UserComponent,
    CategoryComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    approutingmodules
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
