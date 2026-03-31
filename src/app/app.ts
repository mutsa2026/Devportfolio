import { Component, signal, AfterViewInit, OnDestroy } from '@angular/core';

// If EmailJS is loaded via script in index.html, declare it for TS
declare const emailjs: any;

@Component({
  selector: 'app-root',
  templateUrl: './app.html',
  styleUrls: ['./app.css']
})
export class App implements AfterViewInit, OnDestroy {
  protected readonly title = signal('my-app');
  private resizeListener?: () => void;
  private scrollListener?: () => void;
  private mousemoveListener?: (e: MouseEvent) => void;

  ngAfterViewInit(): void {
    this.initializeEmailJS();
    this.setupThemeToggle();
    this.setupMobileNavigation();
    this.setupContactForm();
    this.setupHeaderScroll();
    this.setupContactCardsAnimation();
    this.setupCustomCursor();
    this.setupNameLettersAnimation();
    this.setupInteractiveCube();
    this.setupResponsiveHandlers();
  }

  ngOnDestroy(): void {
    // Clean up event listeners
    if (this.resizeListener) {
      window.removeEventListener('resize', this.resizeListener);
    }
    if (this.scrollListener) {
      window.removeEventListener('scroll', this.scrollListener);
    }
    if (this.mousemoveListener) {
      document.removeEventListener('mousemove', this.mousemoveListener);
    }
  }

  private initializeEmailJS(): void {
    if (typeof emailjs !== 'undefined') {
      emailjs.init('YOUR_PUBLIC_KEY_HERE'); // Replace with your EmailJS public key
    }
  }

  private setupThemeToggle(): void {
    const themeToggle = document.getElementById('themeToggle');
    if (themeToggle) {
      themeToggle.addEventListener('click', () => {
        document.body.classList.toggle('light-mode');
        const isLightMode = document.body.classList.contains('light-mode');
        localStorage.setItem('theme', isLightMode ? 'light' : 'dark');
      });
    }
  }

  private setupMobileNavigation(): void {
    const hamburger = document.querySelector('.hamburger') as HTMLElement;
    const navList = document.querySelector('.nav-list ul') as HTMLElement;

    if (hamburger && navList) {
      hamburger.addEventListener('click', () => {
        hamburger.classList.toggle('active');
        navList.classList.toggle('active');
        document.body.style.overflow = navList.classList.contains('active') ? 'hidden' : '';
      });

      // Close mobile menu when clicking on links
      document.querySelectorAll('.nav-list ul a').forEach(link => {
        link.addEventListener('click', () => {
          hamburger.classList.remove('active');
          navList.classList.remove('active');
          document.body.style.overflow = '';
        });
      });

      // Close mobile menu when clicking outside
      document.addEventListener('click', (e) => {
        const target = e.target as HTMLElement;
        if (navList.classList.contains('active') && 
            !target.closest('.nav-list') && 
            !target.closest('.hamburger')) {
          hamburger.classList.remove('active');
          navList.classList.remove('active');
          document.body.style.overflow = '';
        }
      });
    }
  }

  private setupContactForm(): void {
    const contactForm = document.getElementById('contactForm') as HTMLFormElement | null;

    if (contactForm) {
      contactForm.addEventListener('submit', (e) => {
        e.preventDefault();

        const submitBtn = contactForm.querySelector('.submit-btn') as HTMLButtonElement;
        if (!submitBtn) return;

        const originalText = submitBtn.innerHTML;
        submitBtn.innerHTML = '<i class="fas fa-spinner fa-spin"></i> Sending...';
        submitBtn.disabled = true;

        emailjs.sendForm('YOUR_SERVICE_ID', 'YOUR_TEMPLATE_ID', contactForm)
          .then(() => {
            this.showNotification('Message sent successfully! I\'ll get back to you within 24 hours.', 'success');
            contactForm.reset();
          })
          .catch((error: any) => {
            this.showNotification('Failed to send message. Please try again or email me directly.', 'error');
            console.error('FAILED...', error);
          })
          .finally(() => {
            submitBtn.innerHTML = originalText;
            submitBtn.disabled = false;
          });
      });
    }
  }

  private showNotification(message: string, type: 'success' | 'error'): void {
    const notification = document.createElement('div');
    notification.className = `notification ${type}`;
    notification.innerHTML = `
      <i class="fas fa-${type === 'success' ? 'check-circle' : 'exclamation-circle'}"></i>
      <span>${message}</span>
    `;
    document.body.appendChild(notification);

    setTimeout(() => {
      notification.style.animation = 'slideOut 0.3s ease';
      setTimeout(() => {
        if (document.body.contains(notification)) {
          document.body.removeChild(notification);
        }
      }, 300);
    }, 5000);
  }

  private setupHeaderScroll(): void {
    this.scrollListener = () => {
      const header = document.getElementById('header');
      if (header) {
        if (window.scrollY > 50) {
          header.classList.add('scrolled');
        } else {
          header.classList.remove('scrolled');
        }
      }
    };
    window.addEventListener('scroll', this.scrollListener);
  }

  private setupContactCardsAnimation(): void {
    const observerOptions = { 
      threshold: 0.1, 
      rootMargin: '0px 0px -50px 0px' 
    };

    const observer = new IntersectionObserver((entries) => {
      entries.forEach(entry => {
        if (entry.isIntersecting) {
          const target = entry.target as HTMLElement;
          target.style.animationDelay = target.dataset['delay'] || '0s';
          target.classList.add('animate-in');
        }
      });
    }, observerOptions);

    // Observe contact cards
    document.querySelectorAll<HTMLElement>('.contact-card').forEach((card, index) => {
      card.dataset['delay'] = `${index * 0.1}s`;
      observer.observe(card);
    });
  }

  private setupCustomCursor(): void {
    // Only enable custom cursor on non-touch devices
    if ('ontouchstart' in window) return;

    const cursor = document.querySelector('.cursor') as HTMLElement;
    const cursorFollower = document.querySelector('.cursor-follower') as HTMLElement;

    if (!cursor || !cursorFollower) return;

    this.mousemoveListener = (e: MouseEvent) => {
      cursor.style.left = e.clientX + 'px';
      cursor.style.top = e.clientY + 'px';
      setTimeout(() => {
        cursorFollower.style.left = e.clientX + 'px';
        cursorFollower.style.top = e.clientY + 'px';
      }, 100);
    };

    document.addEventListener('mousemove', this.mousemoveListener);

    // Cursor hover effects
    const hoverElements = document.querySelectorAll(
      'a, button, .service-item, .project-item, .contact-item, .social-item, .name-letter, .skill-card'
    );

    hoverElements.forEach(el => {
      el.addEventListener('mouseenter', () => {
        cursor.style.transform = 'translate(-50%, -50%) scale(1.5)';
        cursor.style.backgroundColor = 'rgba(100, 255, 218, 0.8)';
        cursorFollower.style.transform = 'translate(-50%, -50%) scale(0.5)';
      });

      el.addEventListener('mouseleave', () => {
        cursor.style.transform = 'translate(-50%, -50%) scale(1)';
        cursor.style.backgroundColor = 'rgba(100, 255, 218, 0.5)';
        cursorFollower.style.transform = 'translate(-50%, -50%) scale(1)';
      });
    });
  }

  private setupNameLettersAnimation(): void {
    // Only enable on non-touch devices and larger screens
    if ('ontouchstart' in window || window.innerWidth < 768) return;

    const nameLetters = document.querySelectorAll('.name-letter');

    nameLetters.forEach((letter, index) => {
      letter.addEventListener('mouseenter', () => {
        const htmlLetter = letter as HTMLElement;
        htmlLetter.style.transform = 'translateY(-10px)';
        htmlLetter.style.color = '#64ffda';
        htmlLetter.style.textShadow = '0 10px 20px rgba(100, 255, 218, 0.5)';

        // Create ripple effect
        const ripple = document.createElement('span');
        ripple.style.position = 'absolute';
        ripple.style.width = '100%';
        ripple.style.height = '100%';
        ripple.style.background = 'radial-gradient(circle, rgba(255,255,255,0.8) 0%, transparent 70%)';
        ripple.style.top = '0';
        ripple.style.left = '0';
        ripple.style.borderRadius = '50%';
        ripple.style.transform = 'scale(0)';
        ripple.style.opacity = '1';
        ripple.style.transition = 'transform 0.5s ease, opacity 0.5s ease';

        letter.appendChild(ripple);

        setTimeout(() => {
          ripple.style.transform = 'scale(2)';
          ripple.style.opacity = '0';
        }, 10);

        setTimeout(() => {
          if (letter.contains(ripple)) {
            letter.removeChild(ripple);
          }
        }, 600);
      });

      letter.addEventListener('mouseleave', () => {
        const htmlLetter = letter as HTMLElement;
        htmlLetter.style.transform = 'translateY(0)';
        if (index !== 5) { // don't change color for the teal 'M'
          htmlLetter.style.color = '#e6f1ff';
        }
        htmlLetter.style.textShadow = '2px 2px 4px rgba(0,0,0,0.3)';
      });
    });
  }

  private setupInteractiveCube(): void {
    // Only enable on non-touch devices and larger screens
    if ('ontouchstart' in window || window.innerWidth < 1024) return;

    const cube = document.querySelector('.cube') as HTMLElement;
    if (!cube) return;

    const cubeMoveListener = (e: MouseEvent) => {
      const x = (window.innerWidth / 2 - e.clientX) / 25;
      const y = (window.innerHeight / 2 - e.clientY) / 25;
      cube.style.transform = `rotateX(${-15 - y}deg) rotateY(${-15 - x}deg)`;
    };

    document.addEventListener('mousemove', cubeMoveListener);
    this.mousemoveListener = cubeMoveListener;
  }

  private setupResponsiveHandlers(): void {
    // Handle responsive behavior on resize
    this.resizeListener = () => {
      this.handleResponsiveFeatures();
    };
    window.addEventListener('resize', this.resizeListener);
    
    // Initial call
    this.handleResponsiveFeatures();
  }

  private handleResponsiveFeatures(): void {
    const isMobile = window.innerWidth < 768;
    const isTablet = window.innerWidth < 1024;
    const isTouchDevice = 'ontouchstart' in window;

    // Disable complex animations on mobile/touch devices for better performance
    if (isMobile || isTouchDevice) {
      this.disableNonEssentialAnimations();
    } else {
      this.enableAnimations();
    }

    // Adjust animation delays based on screen size
    this.adjustAnimationDelays(isMobile);
  }

  private disableNonEssentialAnimations(): void {
    // Add a class to body that can be used in CSS to disable animations
    document.body.classList.add('reduced-motion');
    
    // Disable custom cursor on mobile
    const cursor = document.querySelector('.cursor') as HTMLElement;
    const cursorFollower = document.querySelector('.cursor-follower') as HTMLElement;
    if (cursor) cursor.style.display = 'none';
    if (cursorFollower) cursorFollower.style.display = 'none';
  }

  private enableAnimations(): void {
    document.body.classList.remove('reduced-motion');
    
    const cursor = document.querySelector('.cursor') as HTMLElement;
    const cursorFollower = document.querySelector('.cursor-follower') as HTMLElement;
    if (cursor) cursor.style.display = 'block';
    if (cursorFollower) cursorFollower.style.display = 'block';
  }

  private adjustAnimationDelays(isMobile: boolean): void {
    // Adjust animation delays for better mobile performance
    const contactCards = document.querySelectorAll<HTMLElement>('.contact-card');
    contactCards.forEach((card, index) => {
      card.dataset['delay'] = isMobile ? '0s' : `${index * 0.1}s`;
    });
  }
}