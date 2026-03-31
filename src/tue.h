/* Import fonts and icons */
@import url('https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css');
@import url('https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;500;600;700&display=swap');

/* Root variables */
:root {
  --bg-primary: #0a192f;
  --bg-secondary: #112240;
  --bg-tertiary: #172a45;
  --text-primary: #e6f1ff;
  --text-secondary: #8892b0;
  --accent: #64ffda;
  --shadow: rgba(2, 12, 27, 0.7);
  --card-bg: rgba(23, 42, 69, 0.7);
  --gradient-1: linear-gradient(135deg, #0a192f 0%, #112240 50%, #172a45 100%);
  --gradient-2: linear-gradient(135deg, #64ffda 0%, #0a192f 100%);
}

        .light-mode {
            --bg-primary: #ffffff;
            --bg-secondary: #f8f9fa;
            --bg-tertiary: #e9ecef;
            --text-primary: #212529;
            --text-secondary: #6c757d;
            --accent: #20c997;
            --shadow: rgba(0, 0, 0, 0.1);
            --card-bg: rgba(255, 255, 255, 0.95);
            --gradient-1: linear-gradient(135deg, #ffffff 0%, #f8f9fa 50%, #e9ecef 100%);
            --gradient-2: linear-gradient(135deg, #20c997 0%, #ffffff 100%);
        }

        * {
            padding: 0;
            margin: 0;
            box-sizing: border-box;
            transition: background-color 0.3s ease, color 0.3s ease, border-color 0.3s ease;
        }

        html {
            font-size: 10px;
            font-family: 'Poppins', sans-serif;
            scroll-behavior: smooth;
        }

        body {
            background-color: var(--bg-primary);
            color: var(--text-primary);
            line-height: 1.6;
            overflow-x: hidden;
        }

        .section-title {
            font-size: 4rem;
            font-weight: 600;
            color: var(--accent);
            margin-bottom: 30px;
            text-transform: uppercase;
            letter-spacing: 0.2rem;
            text-align: center;
            position: relative;
        }

        .section-title:after {
            content: '';
            position: absolute;
            bottom: -10px;
            left: 50%;
            transform: translateX(-50%);
            width: 80px;
            height: 4px;
            background: var(--accent);
            border-radius: 2px;
        }

        .section-title span {
            color: var(--accent);
        }

        .cta {
            display: inline-block;
            padding: 12px 30px;
            color: var(--bg-primary);
            background-color: var(--accent);
            border: 2px solid var(--accent);
            font-size: 1.8rem;
            text-transform: uppercase;
            letter-spacing: 0.1rem;
            margin-top: 30px;
            transition: all 0.3s ease;
            border-radius: 4px;
            font-weight: 500;
            box-shadow: 0 5px 15px rgba(100, 255, 218, 0.3);
            text-decoration: none;
        }

        .cta:hover {
            background-color: transparent;
            color: var(--accent);
            transform: translateY(-3px);
            box-shadow: 0 8px 20px rgba(100, 255, 218, 0.4);
        }

        .cta.secondary {
            background-color: transparent;
            color: var(--accent);
            margin-left: 15px;
        }

        .cta.secondary:hover {
            background-color: var(--accent);
            color: var(--bg-primary);
        }

        /* Theme toggle: inline inside header nav on desktop, fixed on small screens */
        .theme-toggle-container {
            position: static; /* let it sit in the nav flow */
            display: flex;
            align-items: center;
            gap: 10px;
            margin-right: 12px; /* space between toggle and hamburger */
            background: transparent;
            padding: 0;
            border-radius: 0;
            box-shadow: none;
            border: none;
        }

        .theme-label {
            font-size: 1.4rem;
            font-weight: 600;
            color: var(--text-primary);
            text-transform: uppercase;
            letter-spacing: 1px;
        }

        .theme-toggle {
            position: relative;
            width: 70px;
            height: 35px;
            background: var(--bg-tertiary);
            border-radius: 50px;
            cursor: pointer;
            border: 2px solid var(--accent);
            transition: all 0.3s ease;
        }

        .theme-toggle:hover {
            transform: scale(1.05);
            box-shadow: 0 0 15px var(--accent);
        }

        .toggle-slider {
            position: absolute;
            top: 3px;
            left: 3px;
            width: 25px;
            height: 25px;
            background: var(--accent);
            border-radius: 50%;
            transition: all 0.3s ease;
            display: flex;
            align-items: center;
            justify-content: center;
            color: var(--bg-primary);
            font-size: 1.2rem;
        }

        .light-mode .toggle-slider {
            transform: translateX(35px);
        }

        .theme-icons {
            position: absolute;
            top: 50%;
            transform: translateY(-50%);
            display: flex;
            justify-content: space-between;
            width: 100%;
            padding: 0 10px;
            pointer-events: none;
        }

        .theme-icons i {
            font-size: 1.4rem;
            color: var(--text-secondary);
            transition: color 0.3s ease;
        }

        .theme-toggle:hover .theme-icons i {
            color: var(--accent);
        }

        /* Header */
        #header {
            position: fixed;
            z-index: 1000;
            left: 0;
            top: 0;
            width: 100vw;
            height: auto;
            transition: all 0.3s ease;
            background-color: var(--bg-primary);
        }

        #header.scrolled {
            background-color: var(--bg-primary);
            box-shadow: 0 5px 20px var(--shadow);
        }

        #header .header {
            min-height: 8vh;
            background-color: var(--bg-primary);
            transition: 0.3s ease background-color;
        }

        #header .nav-bar {
            display: flex;
            align-items: center;
            justify-content: space-between;
            width: 100%;
            height: 100%;
            max-width: 1300px;
            margin: 0 auto;
            padding: 0 30px;
            position: relative; /* allow absolute children like theme toggle */
        }

        #header .brand h1 {
            font-size: 2.5rem;
            text-transform: uppercase;
            color: var(--text-primary);
            font-weight: 600;
        }

        #header .brand h1 span {
            color: var(--accent);
        }

        #header .nav-list ul {
            list-style: none;
            position: absolute;
            background-color: var(--bg-primary);
            width: 100vw;
            height: 100vh;
            left: 100%;
            top: 0;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            z-index: 1;
            overflow-x: hidden;
            transition: 0.5s ease left;
        }

        #header .nav-list ul.active {
            left: 0%;
        }

        #header .nav-list ul li {
            margin: 20px 0;
        }

        #header .nav-list ul a {
            font-size: 2.5rem;
            font-weight: 500;
            letter-spacing: 0.2rem;
            text-decoration: none;
            color: var(--text-primary);
            text-transform: uppercase;
            padding: 20px;
            display: block;
            transition: 0.3s ease color;
        }

        #header .nav-list ul a:hover {
            color: var(--accent);
        }

        #header .hamburger {
            height: 50px;
            width: 50px;
            display: inline-block;
            border: 2px solid var(--text-primary);
            border-radius: 50%;
            position: relative;
            display: flex;
            align-items: center;
            justify-content: center;
            z-index: 100;
            cursor: pointer;
            transition: 0.3s ease all;
        }

        #header .hamburger .bar {
            height: 2px;
            width: 25px;
            position: relative;
            background-color: var(--text-primary);
            z-index: -1;
        }

        #header .hamburger .bar::after,
        #header .hamburger .bar::before {
            content: '';
            position: absolute;
            height: 100%;
            width: 100%;
            left: 0;
            background-color: var(--text-primary);
            transition: 0.3s ease;
            transition-property: top, bottom;
        }

        #header .hamburger .bar::after {
            top: 8px;
        }

        #header .hamburger .bar::before {
            bottom: 8px;
        }

        #header .hamburger.active .bar::before {
            bottom: 0;
        }

        #header .hamburger.active .bar::after {
            top: 0;
        }

        /* PERFECT HERO SECTION - ALL ELEMENTS VISIBLE */
        #hero {
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            padding: 100px 20px 60px;
            background: var(--gradient-1);
            color: var(--text-primary);
            position: relative;
            overflow: hidden;
        }

        #hero::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: url('data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 100" preserveAspectRatio="none"><path fill="rgba(100,255,218,0.03)" d="M0,0 L100,0 L100,100 L0,100 Z"/><path fill="rgba(100,255,218,0.05)" d="M0,0 C50,50 50,50 100,0 L100,100 L0,100 Z"/></svg>');
            background-size: cover;
            z-index: 0;
        }

        .hero-content {
            display: flex;
            align-items: center;
            justify-content: space-between;
            gap: 60px;
            max-width: 1200px;
            width: 100%;
            position: relative;
            z-index: 2;
        }

        .hero-image-container {
            flex: 1;
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .image-frame {
            position: relative;
            width: 60%;           /* user requested increase to 60 */
            max-width: 700px;     /* cap the size on very large screens */
            aspect-ratio: 1 / 1;  /* keep square shape */
            border-radius: 20px;
            background: var(--gradient-2);
            padding: 20px;
            box-shadow: 
                0 10px 30px rgba(0, 0, 0, 0.3),
                0 0 0 4px var(--accent),
                inset 0 0 20px rgba(100, 255, 218, 0.1);
            animation: float 6s ease-in-out infinite;
            transition: all 0.3s ease;
            overflow: hidden;
            display: flex;
            align-items: center;
            justify-content: center;
        }

        @keyframes float {
            0%, 100% { transform: translateY(0) rotate(0deg); }
            50% { transform: translateY(-15px) rotate(1deg); }
        }

        @keyframes rotate {
            0% { transform: rotate(0deg); }
            100% { transform: rotate(360deg); }
        }

        .image-frame::before {
            content: '';
            position: absolute;
            top: -2px;
            left: -2px;
            right: -2px;
            bottom: -2px;
            background: linear-gradient(45deg, var(--accent), transparent, var(--accent), transparent, var(--accent));
            z-index: -1;
            border-radius: 22px;
            animation: rotate 8s linear infinite;
        }

        .image-frame::after {
            content: '';
            position: absolute;
            top: 5px;
            left: 5px;
            right: 5px;
            bottom: 5px;
            border: 2px solid rgba(100, 255, 218, 0.3);
            border-radius: 15px;
            z-index: 1;
            pointer-events: none;
        }

        .image-frame:hover {
            transform: scale(1.05) rotate(2deg);
            box-shadow: 
                0 15px 40px rgba(0, 0, 0, 0.4),
                0 0 0 4px var(--accent),
                inset 0 0 30px rgba(100, 255, 218, 0.2);
        }

        #hero img {
            width: 100%;
            height: 100%;
            border-radius: 10px;
            object-fit: cover;
            object-position: center 35%; /* keep face visible; adjust as needed */
            border: 2px solid var(--bg-primary);
            position: relative;
            z-index: 1;
        }
        .name-container {
            display: flex;
            flex-wrap: wrap;
            gap: 8px;
            margin: 25px 0;
        }

        .name-letter {
            font-size: 4.5rem;
            font-weight: 700;
            display: inline-block;
            transition: all 0.3s ease;
            text-shadow: 2px 2px 4px rgba(0,0,0,0.3);
            position: relative;
        }

        .name-letter:hover {
            transform: translateY(-5px);
            color: var(--accent) !important;
        }

        .name-letter::after {
            content: '';
            position: absolute;
            bottom: -10px;
            left: 0;
            width: 100%;
            height: 5px;
            background: var(--accent);
            border-radius: 50%;
            filter: blur(5px);
            opacity: 0;
            transition: all 0.3s ease;
        }

        .name-letter:hover::after {
            opacity: 1;
            animation: fire-flicker 1s infinite alternate;
        }

        @keyframes fire-flicker {
            0%, 100% {
                transform: scale(1);
                opacity: 0.8;
            }
            50% {
                transform: scale(1.1);
                opacity: 1;
            }
        }

        #hero p {
            font-size: 1.8rem;
            color: var(--text-secondary);
            margin-bottom: 35px;
            line-height: 1.7;
            max-width: 500px;
        }

        .hero-buttons {
            display: flex;
            gap: 20px;
            flex-wrap: wrap;
            margin-top: 30px;
        }

        /* 3D Cube Section */
        #cube-section {
            background-color: var(--bg-secondary);
            padding: 80px 0;
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .cube-container {
            position: relative;
            width: 200px;
            height: 200px;
            perspective: 800px;
            margin: 0 auto;
        }

        .cube {
            position: relative;
            width: 100%;
            height: 100%;
            transform-style: preserve-3d;
            transform: rotateX(-15deg) rotateY(-15deg);
            transition: transform 0.5s ease;
            animation: cube-rotate 15s infinite linear;
        }

        .cube-face {
            position: absolute;
            width: 200px;
            height: 200px;
            background: rgba(100, 255, 218, 0.1);
            border: 2px solid var(--accent);
            display: flex;
            align-items: center;
            justify-content: center;
            flex-direction: column;
            color: var(--text-primary);
            font-size: 1.6rem;
            text-align: center;
            padding: 20px;
            backface-visibility: visible;
        }

        .cube-face i {
            font-size: 3rem;
            margin-bottom: 15px;
            color: var(--accent);
        }

        .cube-face-front {
            transform: translateZ(100px);
        }
        .cube-face-back {
            transform: rotateY(180deg) translateZ(100px);
        }
        .cube-face-right {
            transform: rotateY(90deg) translateZ(100px);
        }
        .cube-face-left {
            transform: rotateY(-90deg) translateZ(100px);
        }
        .cube-face-top {
            transform: rotateX(90deg) translateZ(100px);
        }
        .cube-face-bottom {
            transform: rotateX(-90deg) translateZ(100px);
        }

        @keyframes cube-rotate {
            0% {
                transform: rotateX(-15deg) rotateY(0deg);
            }
            100% {
                transform: rotateX(-15deg) rotateY(360deg);
            }
        }

        /* Services Section */
        #services {
            background-color: var(--bg-primary);
            padding: 100px 0;
        }

        #services .services {
            flex-direction: column;
            text-align: center;
            max-width: 1200px;
            margin: 0 auto;
            padding: 0 20px;
        }

        #services .service-top {
            max-width: 800px;
            margin: 0 auto 50px;
        }

        #services .service-top p {
            font-size: 1.6rem;
            color: var(--text-secondary);
            line-height: 1.8;
        }

        #services .service-bottom {
            display: flex;
            align-items: center;
            justify-content: center;
            flex-wrap: wrap;
            gap: 30px;
        }

        #services .service-item {
            flex: 1 1 300px;
            background-color: var(--bg-tertiary);
            padding: 40px 30px;
            border-radius: 10px;
            box-shadow: 0 5px 30px var(--shadow);
            transition: all 0.3s ease;
            text-align: left;
            position: relative;
            overflow: hidden;
        }

        #services .service-item::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 5px;
            background: linear-gradient(90deg, var(--accent), var(--bg-primary));
            transform: scaleX(0);
            transform-origin: left;
            transition: transform 0.5s ease;
        }

        #services .service-item:hover::before {
            transform: scaleX(1);
        }

        #services .service-item:hover {
            transform: translateY(-10px);
            box-shadow: 0 15px 30px rgba(100, 255, 218, 0.1);
        }

        #services .service-item .icon {
            height: 70px;
            width: 70px;
            margin-bottom: 20px;
            display: flex;
            align-items: center;
            justify-content: center;
            background-color: rgba(100, 255, 218, 0.1);
            border-radius: 50%;
            color: var(--accent);
            font-size: 2.5rem;
            transition: all 0.3s ease;
        }

        #services .service-item:hover .icon {
            background-color: var(--accent);
            color: var(--bg-primary);
            transform: rotateY(180deg);
        }

        #services .service-item h2 {
            font-size: 2rem;
            font-weight: 600;
            margin-bottom: 15px;
            color: var(--text-primary);
        }

        #services .service-item p {
            font-size: 1.5rem;
            color: var(--text-secondary);
            line-height: 1.8;
        }

        /* Projects Section */
        #projects {
            padding: 100px 0;
            background-color: var(--bg-secondary);
        }

        #projects .projects {
            flex-direction: column;
            max-width: 1200px;
            margin: 0 auto;
            padding: 0 20px;
        }

        #projects .projects-header {
            margin-bottom: 50px;
        }

        #projects .all-projects {
            display: flex;
            flex-direction: column;
            gap: 30px;
        }

        #projects .project-item {
            display: flex;
            background-color: var(--bg-tertiary);
            border-radius: 10px;
            overflow: hidden;
            box-shadow: 0 5px 20px var(--shadow);
            transition: all 0.3s ease;
            position: relative;
        }

        #projects .project-item::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: linear-gradient(135deg, rgba(100, 255, 218, 0.1) 0%, rgba(10, 25, 47, 0.1) 100%);
            opacity: 0;
            transition: opacity 0.3s ease;
            z-index: 1;
        }

        #projects .project-item:hover::before {
            opacity: 1;
        }

        #projects .project-item:hover {
            transform: translateY(-5px);
            box-shadow: 0 15px 30px rgba(100, 255, 218, 0.1);
        }

        #projects .project-info {
            padding: 40px;
            flex: 1;
            display: flex;
            flex-direction: column;
            justify-content: center;
            position: relative;
            z-index: 2;
        }

        #projects .project-info h1 {
            font-size: 2.8rem;
            font-weight: 600;
            margin-bottom: 10px;
            color: var(--text-primary);
        }

        #projects .project-info .tagline {
            font-size: 1.5rem;
            color: var(--accent);
            margin-bottom: 15px;
            font-weight: 500;
        }

        #projects .project-info p {
            font-size: 1.5rem;
            color: var(--text-secondary);
            margin-bottom: 20px;
            line-height: 1.8;
        }

        .tech-tags {
            display: flex;
            flex-wrap: wrap;
            gap: 10px;
            margin-bottom: 20px;
        }

        .tech-tags span {
            background-color: rgba(100, 255, 218, 0.1);
            color: var(--accent);
            padding: 5px 15px;
            border-radius: 50px;
            font-size: 1.2rem;
            font-weight: 500;
            transition: all 0.3s ease;
        }

        .tech-tags span:hover {
            background-color: var(--accent);
            color: var(--bg-primary);
            transform: translateY(-2px);
        }

        .project-links {
            display: flex;
            gap: 15px;
        }

        .project-links a {
            position: relative;
            z-index: 2;
            display: flex;
            align-items: center;
            gap: 8px;
            padding: 8px 20px;
            background-color: var(--accent);
            color: var(--bg-primary);
            border-radius: 50px;
            font-size: 1.4rem;
            text-decoration: none;
            transition: all 0.3s ease;
            cursor: pointer;
        }

        .project-links a:hover {
            background-color: rgba(100, 255, 218, 0.1);
            color: var(--accent);
            transform: translateY(-2px);
        }

        .project-links a.secondary {
            background-color: transparent;
            border: 1px solid var(--accent);
            color: var(--accent);
        }

        .project-links a.secondary:hover {
            background-color: var(--accent);
            color: var(--bg-primary);
        }

        #projects .project-img {
            flex: 1;
            min-height: 300px;
            display: flex;
            align-items: center;
            justify-content: center;
            background-color: rgba(10, 25, 47, 0.5);
            position: relative;
            overflow: hidden;
        }

        .project-icon {
            font-size: 10rem;
            color: var(--accent);
            opacity: 0.2;
            transition: all 0.5s ease;
        }

        #projects .project-item:hover .project-icon {
            transform: scale(1.1);
            opacity: 0.3;
        }

        /* About Section */
        #about {
            padding: 100px 0;
            background-color: var(--bg-primary);
            position: relative;
        }

        #about::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: url('data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 100" preserveAspectRatio="none"><path fill="rgba(17,34,64,0.5)" d="M0,0 L100,0 L100,100 L0,100 Z" /><path fill="rgba(10,25,47,0.5)" d="M0,0 C50,50 50,50 100,0 L100,100 L0,100 Z" /></svg>');
            background-size: cover;
            z-index: 0;
            opacity: 0.5;
        }

        #about .about {
            max-width: 1200px;
            margin: 0 auto;
            padding: 0 20px;
            display: flex;
            align-items: center;
            gap: 50px;
            position: relative;
            z-index: 1;
        }

        #about .col-left {
            flex: 1;
            position: relative;
        }

        #about .col-right {
            flex: 1;
        }

        #about .about-img {
            width: 100%;
            max-width: 400px;
            height: 500px;
            background-color: var(--bg-tertiary);
            border-radius: 10px;
            display: flex;
            align-items: center;
            justify-content: center;
            box-shadow: 0 5px 20px var(--shadow);
            overflow: hidden;
            position: relative;
        }

        #about .about-img::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: linear-gradient(135deg, rgba(100, 255, 218, 0.1) 0%, rgba(10, 25, 47, 0.1) 100%);
            z-index: 1;
        }

        .profile-icon {
            font-size: 15rem;
            color: var(--accent);
            opacity: 0.2;
            z-index: 0;
        }

        /* Skills Grid */
        .skills-grid {
            display: grid;
            grid-template-columns: repeat(auto-fill, minmax(150px, 1fr));
            gap: 20px;
            margin-top: 30px;
        }

        .skill-card {
            background-color: var(--bg-tertiary);
            border-radius: 8px;
            padding: 20px;
            text-align: center;
            transition: all 0.3s ease;
            box-shadow: 0 5px 15px var(--shadow);
        }

        .skill-card:hover {
            transform: translateY(-5px);
            box-shadow: 0 10px 25px rgba(100, 255, 218, 0.2);
        }

        .skill-card i {
            font-size: 3rem;
            color: var(--accent);
            margin-bottom: 15px;
        }

        .skill-card h3 {
            font-size: 1.6rem;
            color: var(--text-primary);
            margin-bottom: 10px;
        }

        /* Enhanced Contact Section */
        #contact {
            padding: 120px 0;
            background-color: var(--bg-secondary);
            position: relative;
            overflow: hidden;
        }

        #contact::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: url('data:image/svg+xml;utf8,<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 100" preserveAspectRatio="none"><path fill="rgba(100,255,218,0.03)" d="M0,0 L100,0 L100,100 L0,100 Z"/><path fill="rgba(100,255,218,0.05)" d="M0,0 C50,50 50,50 100,0 L100,100 L0,100 Z"/></svg>');
            background-size: cover;
            z-index: 0;
        }

        #contact .contact {
            max-width: 1200px;
            margin: 0 auto;
            padding: 0 20px;
            flex-direction: column;
            position: relative;
            z-index: 2;
        }

        .contact-header {
            text-align: center;
            margin-bottom: 60px;
        }

        .contact-header p {
            font-size: 1.8rem;
            color: var(--text-secondary);
            max-width: 600px;
            margin: 0 auto;
            line-height: 1.6;
        }

        .contact-container {
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 60px;
            margin-top: 50px;
        }

        .contact-info {
            display: flex;
            flex-direction: column;
            gap: 30px;
        }

        .contact-card {
            background: var(--card-bg);
            border-radius: 20px;
            padding: 40px 30px;
            box-shadow: 0 15px 35px var(--shadow);
            transition: all 0.4s ease;
            border: 1px solid rgba(100, 255, 218, 0.1);
            display: flex;
            align-items: center;
            gap: 25px;
            position: relative;
            overflow: hidden;
        }

        .contact-card::before {
            content: '';
            position: absolute;
            top: 0;
            left: -100%;
            width: 100%;
            height: 100%;
            background: linear-gradient(90deg, transparent, rgba(100, 255, 218, 0.1), transparent);
            transition: left 0.6s ease;
        }

        .contact-card:hover::before {
            left: 100%;
        }

        .contact-card:hover {
            transform: translateY(-10px) scale(1.02);
            box-shadow: 0 20px 40px rgba(100, 255, 218, 0.2);
            border-color: var(--accent);
        }

        .contact-icon {
            width: 80px;
            height: 80px;
            display: flex;
            align-items: center;
            justify-content: center;
            background: rgba(100, 255, 218, 0.1);
            border-radius: 50%;
            color: var(--accent);
            font-size: 2.5rem;
            transition: all 0.4s ease;
            flex-shrink: 0;
            position: relative;
            z-index: 2;
        }

        .contact-card:hover .contact-icon {
            background: var(--accent);
            color: var(--bg-primary);
            transform: scale(1.1) rotate(10deg);
            box-shadow: 0 0 20px rgba(100, 255, 218, 0.4);
        }

        .contact-details {
            flex: 1;
            position: relative;
            z-index: 2;
        }

        .contact-details h3 {
            font-size: 2.2rem;
            font-weight: 600;
            margin-bottom: 12px;
            color: var(--text-primary);
        }

        .contact-details p {
            font-size: 1.6rem;
            color: var(--text-secondary);
            margin-bottom: 10px;
            line-height: 1.6;
        }

        .contact-details a {
            color: var(--text-secondary);
            text-decoration: none;
            transition: all 0.3s ease;
            display: block;
            font-size: 1.5rem;
        }

        .contact-details a:hover {
            color: var(--accent);
            transform: translateX(5px);
        }

        /* Enhanced Contact Form */
        .contact-form-container {
            background: var(--card-bg);
            border-radius: 20px;
            padding: 50px 40px;
            box-shadow: 0 15px 35px var(--shadow);
            border: 1px solid rgba(100, 255, 218, 0.1);
            position: relative;
            overflow: hidden;
        }

        .contact-form-container::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 5px;
            background: linear-gradient(90deg, var(--accent), transparent);
        }

        .contact-form-container h3 {
            font-size: 2.8rem;
            font-weight: 600;
            margin-bottom: 30px;
            color: var(--text-primary);
            text-align: center;
            position: relative;
        }

        .contact-form-container h3::after {
            content: '';
            position: absolute;
            bottom: -10px;
            left: 50%;
            transform: translateX(-50%);
            width: 60px;
            height: 3px;
            background: var(--accent);
            border-radius: 2px;
        }

        .form-group {
            margin-bottom: 25px;
            position: relative;
        }

        .form-group label {
            display: block;
            font-size: 1.5rem;
            color: var(--text-secondary);
            margin-bottom: 8px;
            font-weight: 500;
            transition: color 0.3s ease;
        }

        .form-control {
            width: 100%;
            padding: 18px 20px;
            background: var(--bg-primary);
            border: 2px solid rgba(100, 255, 218, 0.2);
            border-radius: 12px;
            font-size: 1.5rem;
            color: var(--text-primary);
            transition: all 0.3s ease;
            font-family: 'Poppins', sans-serif;
        }

        .form-control:focus {
            outline: none;
            border-color: var(--accent);
            box-shadow: 0 0 0 4px rgba(100, 255, 218, 0.1);
            transform: translateY(-2px);
        }

        textarea.form-control {
            min-height: 180px;
            resize: vertical;
        }

        .submit-btn {
            width: 100%;
            padding: 18px;
            background: var(--accent);
            color: var(--bg-primary);
            border: none;
            border-radius: 12px;
            font-size: 1.7rem;
            font-weight: 600;
            cursor: pointer;
            transition: all 0.3s ease;
            text-transform: uppercase;
            letter-spacing: 1px;
            position: relative;
            overflow: hidden;
        }

        .submit-btn::before {
            content: '';
            position: absolute;
            top: 0;
            left: -100%;
            width: 100%;
            height: 100%;
            background: linear-gradient(90deg, transparent, rgba(255,255,255,0.2), transparent);
            transition: left 0.5s ease;
        }

        .submit-btn:hover::before {
            left: 100%;
        }

        .submit-btn:hover {
            background: transparent;
            color: var(--accent);
            border: 2px solid var(--accent);
            transform: translateY(-3px);
            box-shadow: 0 10px 25px rgba(100, 255, 218, 0.3);
        }

        /* Social Links */
        .contact-social {
            display: flex;
            justify-content: center;
            gap: 20px;
            margin-top: 50px;
        }

        .social-link {
            width: 60px;
            height: 60px;
            display: flex;
            align-items: center;
            justify-content: center;
            background: var(--card-bg);
            border-radius: 50%;
            color: var(--text-primary);
            font-size: 2rem;
            transition: all 0.3s ease;
            text-decoration: none;
            border: 2px solid rgba(100, 255, 218, 0.1);
            position: relative;
            overflow: hidden;
        }

        .social-link::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: var(--accent);
            border-radius: 50%;
            transform: scale(0);
            transition: transform 0.3s ease;
            z-index: -1;
        }

        .social-link:hover::before {
            transform: scale(1);
        }

        .social-link:hover {
            color: var(--bg-primary);
            transform: translateY(-5px) rotate(10deg);
            box-shadow: 0 10px 20px rgba(100, 255, 218, 0.3);
            border-color: var(--accent);
        }

        /* Footer */
        #footer {
            background-color: var(--bg-primary);
            padding: 50px 0 20px;
            color: var(--text-primary);
            position: relative;
        }

        #footer .footer {
            max-width: 1200px;
            margin: 0 auto;
            padding: 0 20px;
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        #footer .brand h1 {
            font-size: 3rem;
            margin-bottom: 20px;
        }

        #footer h2 {
            font-size: 1.8rem;
            font-weight: 400;
            margin-bottom: 30px;
            text-align: center;
        }

        #footer .social-icon {
            display: flex;
            gap: 20px;
            margin-bottom: 30px;
        }

        #footer .social-item {
            width: 50px;
            height: 50px;
            display: flex;
            align-items: center;
            justify-content: center;
            background-color: rgba(100, 255, 218, 0.1);
            border-radius: 50%;
            transition: all 0.3s ease;
            position: relative;
            overflow: hidden;
        }

        #footer .social-item::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: linear-gradient(45deg, var(--accent), var(--bg-primary));
            opacity: 0;
            transition: opacity 0.3s ease;
        }

        #footer .social-item:hover::before {
            opacity: 1;
        }

        #footer .social-item:hover {
            background-color: transparent;
            transform: translateY(-5px) scale(1.1);
        }

        #footer .social-item i {
            font-size: 2rem;
            color: var(--text-primary);
            position: relative;
            z-index: 1;
        }

        #footer p {
            font-size: 1.4rem;
            opacity: 0.8;
        }

        /* Notification Styles */
        .notification {
            position: fixed;
            top: 20px;
            right: 20px;
            padding: 20px 25px;
            border-radius: 12px;
            box-shadow: 0 10px 30px var(--shadow);
            z-index: 10000;
            max-width: 400px;
            animation: slideIn 0.3s ease;
            display: flex;
            align-items: center;
            gap: 15px;
            border-left: 4px solid;
        }

        .notification.success {
            background: var(--card-bg);
            color: var(--text-primary);
            border-left-color: #4CAF50;
        }

        .notification.error {
            background: var(--card-bg);
            color: var(--text-primary);
            border-left-color: #f44336;
        }

        .notification i {
            font-size: 2rem;
        }

        .notification.success i {
            color: #4CAF50;
        }

        .notification.error i {
            color: #f44336;
        }

        @keyframes slideIn {
            from { transform: translateX(100%); opacity: 0; }
            to { transform: translateX(0); opacity: 1; }
        }

        @keyframes slideOut {
            from { transform: translateX(0); opacity: 1; }
            to { transform: translateX(100%); opacity: 0; }
        }

        .submit-btn:disabled {
            opacity: 0.7;
            cursor: not-allowed;
            transform: none !important;
        }

        .fa-spinner {
            animation: spin 1s linear infinite;
        }

        @keyframes spin {
            0% { transform: rotate(0deg); }
            100% { transform: rotate(360deg); }
        }

        /* Responsive Design */
        @media (max-width: 992px) {
            .contact-container {
                grid-template-columns: 1fr;
                gap: 40px;
            }
            
            .contact-info {
                order: 2;
            }
            
            .contact-form-container {
                order: 1;
            }
            
            #about .about {
                flex-direction: column;
            }
            #about .col-left {
                margin-bottom: 50px;
            }

            .hero-content {
                flex-direction: column;
                text-align: center;
                gap: 40px;
            }

            .hero-text {
                text-align: center;
            }

            .hero-buttons {
                justify-content: center;
            }

            .hero-image-container {
                width: 350px;
                height: 350px;
            }

            .image-frame {
                width: 330px;
                height: 330px;
            }
        }

        @media (max-width: 768px) {
            .section-title {
                font-size: 3rem;
            }
            
            .contact-card {
                padding: 30px 20px;
                flex-direction: column;
                text-align: center;
            }
            
            .contact-form-container {
                padding: 40px 25px;
            }
            
            .contact-details h3 {
                font-size: 2rem;
            }

            .hero-image-container {
                width: 300px;
                height: 300px;
            }

            .image-frame {
                width: 280px;
                height: 280px;
            }

            #hero h1 {
                font-size: 3.5rem;
            }

            .name-letter {
                font-size: 3.5rem;
            }

            .theme-toggle-container {
                top: 20px;
                right: 20px;
                padding: 10px 15px;
            }

            .theme-label {
                font-size: 1.2rem;
            }

            .theme-toggle {
                width: 60px;
                height: 30px;
            }

            .toggle-slider {
                width: 22px;
                height: 22px;
                top: 2px;
                left: 2px;
            }

            .light-mode .toggle-slider {
                transform: translateX(30px);
            }
        }

        @media (max-width: 576px) {
            .section-title {
                font-size: 2.5rem;
            }
            
            .contact-icon {
                width: 70px;
                height: 70px;
                font-size: 2.2rem;
            }
            
            .hero-image-container {
                width: 280px;
                height: 280px;
            }

            .image-frame {
                width: 260px;
                height: 260px;
            }

            #hero h1 {
                font-size: 3rem;
            }

            .name-letter {
                font-size: 3rem;
            }

            #hero p {
                font-size: 1.6rem;
            }

            .theme-toggle-container {
                top: 15px;
                right: 15px;
                padding: 8px 12px;
            }

            .theme-label {
                font-size: 1rem;
            }

            .theme-toggle {
                width: 55px;
                height: 28px;
            }

            /* On very small screens keep the toggle fixed to avoid overlap */
            .theme-toggle-container {
                position: fixed;
                top: 12px;
                right: 12px;
                transform: none;
                padding: 6px 10px;
                border-radius: 36px;
                background: var(--bg-secondary);
                box-shadow: 0 5px 20px var(--shadow);
                border: 1px solid rgba(100,255,218,0.12);
            }

            .theme-label { display: none; }

            .toggle-slider {
                width: 20px;
                height: 20px;
            }

            .light-mode .toggle-slider {
                transform: translateX(27px);
            }
        }

      /* Enhanced Mobile Responsive Fixes for Hero Section Name */
@media (max-width: 768px) {
    #hero {
        padding: 80px 15px 40px;
        min-height: 100vh;
    }
    
    .hero-content {
        flex-direction: column;
        text-align: center;
        gap: 30px;
    }
    
    .hero-text {
        text-align: center;
        width: 100%;
    }
    
    /* Enhanced name container for better fit */
    .name-container {
        display: flex;
        justify-content: center;
        flex-wrap: nowrap;
        gap: 6px;
        margin: 20px 0;
        overflow: visible;
        width: 100%;
        padding: 0 5px;
    }
    
    .name-letter {
        font-size: 3.8rem; /* Increased from 3.2rem */
        font-weight: 700;
        flex-shrink: 1;
        min-width: auto;
        line-height: 1.1;
    }
    
    /* Ensure the name header has proper spacing */
    #hero h1 {
        font-size: 3.2rem; /* Increased from 2.8rem */
        line-height: 1.1;
        margin-bottom: 15px;
        width: 100%;
    }
    
    /* Adjust image size for better mobile fit */
    .hero-image-container {
        width: 100%;
        max-width: 320px; /* Increased from 280px */
        margin: 0 auto;
    }
    
    .image-frame {
        width: 100%;
        max-width: 280px; /* Increased from 250px */
        height: 280px; /* Increased from 250px */
    }
    
    /* Improve text readability */
    #hero p {
        font-size: 1.7rem; /* Increased from 1.6rem */
        line-height: 1.6;
        margin: 0 auto 25px;
        max-width: 100%;
        padding: 0 15px; /* Increased padding */
    }
    
    /* Center buttons and make them stack */
    .hero-buttons {
        justify-content: center;
        flex-direction: column;
        align-items: center;
        gap: 15px;
        margin-top: 25px;
    }
    
    .cta {
        width: 100%;
        max-width: 280px; /* Increased from 250px */
        text-align: center;
        margin: 5px 0;
        padding: 14px 30px; /* Increased padding */
        font-size: 1.8rem; /* Increased font size */
    }
    
    .cta.secondary {
        margin-left: 0;
    }
}

/* Extra small devices (phones under 480px) */
@media (max-width: 480px) {
    #hero {
        padding: 80px 12px 35px; /* Increased padding */
    }
    
    /* Further adjustments for very small screens */
    .name-letter {
        font-size: 3.2rem; /* Increased from 2.8rem */
    }
    
    #hero h1 {
        font-size: 2.8rem; /* Increased from 2.4rem */
    }
    
    .name-container {
        gap: 4px; /* Increased gap */
        margin: 18px 0;
    }
    
    /* Larger image on very small screens */
    .hero-image-container {
        max-width: 280px; /* Increased from 240px */
    }
    
    .image-frame {
        max-width: 250px; /* Increased from 220px */
        height: 250px; /* Increased from 220px */
    }
    
    #hero p {
        font-size: 1.6rem; /* Increased from 1.5rem */
        padding: 0 10px; /* Increased padding */
    }
    
    /* Make buttons more prominent */
    .cta {
        padding: 12px 25px;
        font-size: 1.7rem;
        max-width: 260px; /* Increased from 220px */
    }
}

/* Ultra-small devices (phones under 360px) */
@media (max-width: 360px) {
    .name-letter {
        font-size: 2.8rem; /* Increased from 2.4rem */
    }
    
    #hero h1 {
        font-size: 2.4rem; /* Increased from 2rem */
    }
    
    .name-container {
        gap: 3px; /* Increased gap */
    }
    
    .hero-image-container {
        max-width: 240px; /* Increased from 200px */
    }
    
    .image-frame {
        max-width: 220px; /* Increased from 180px */
        height: 220px; /* Increased from 180px */
    }
    
    #hero p {
        font-size: 1.5rem; /* Increased from 1.4rem */
    }
    
    .cta {
        max-width: 240px; /* Increased button width */
    }
}

/* Additional specific fixes for name display */
@media (max-width: 320px) {
    .name-letter {
        font-size: 2.6rem; /* Even on smallest screens, keep readable */
    }

    #hero h1 {
        font-size: 2.2rem;
    }

    .name-container {
        gap: 2px;
        transform: scale(0.95); /* Slight scale to fit everything */
    }
}

/* Ultra-small screens (phones under 280px) */
@media (max-width: 280px) {
    /* Header adjustments */
    #header .brand h1 {
        font-size: 1.8rem;
    }

    #header .nav-list ul a {
        font-size: 1.8rem;
        padding: 15px;
    }

    /* Hero section ultra-small adjustments */
    #hero {
        padding: 60px 8px 25px;
        min-height: auto;
    }

    .hero-content {
        gap: 20px;
    }

    .name-letter {
        font-size: 2.2rem;
        font-weight: 600;
    }

    #hero h1 {
        font-size: 1.8rem;
        margin-bottom: 10px;
    }

    .name-container {
        gap: 1px;
        margin: 12px 0;
        transform: scale(0.9);
    }

    #hero p {
        font-size: 1.4rem;
        line-height: 1.5;
        margin: 0 auto 20px;
        padding: 0 8px;
        max-width: 100%;
    }

    .hero-buttons {
        gap: 12px;
        margin-top: 20px;
    }

    .cta {
        padding: 10px 20px;
        font-size: 1.5rem;
        max-width: 220px;
        margin: 3px 0;
    }

    .hero-image-container {
        max-width: 200px;
    }

    .image-frame {
        max-width: 180px;
        height: 180px;
    }

    /* Section titles */
    .section-title {
        font-size: 2rem;
        margin-bottom: 25px;
    }

    .section-title:after {
        width: 60px;
        height: 3px;
        bottom: -8px;
    }

    /* Services section */
    #services {
        padding: 60px 0;
    }

    #services .service-item {
        padding: 30px 20px;
    }

    #services .service-item h2 {
        font-size: 1.8rem;
        margin-bottom: 12px;
    }

    #services .service-item p {
        font-size: 1.4rem;
    }

    /* Projects section */
    #projects {
        padding: 60px 0;
    }

    #projects .project-item {
        flex-direction: column;
    }

    #projects .project-info {
        padding: 25px 20px;
    }

    #projects .project-info h1 {
        font-size: 2.2rem;
        margin-bottom: 8px;
    }

    #projects .project-info p {
        font-size: 1.4rem;
        margin-bottom: 15px;
    }

    .tech-tags span {
        font-size: 1.1rem;
        padding: 4px 12px;
    }

    .project-links a {
        font-size: 1.3rem;
        padding: 6px 16px;
    }

    /* About section */
    #about {
        padding: 60px 0;
    }

    #about .about {
        gap: 30px;
    }

    #about .about-img {
        max-width: 300px;
        height: 400px;
    }

    .profile-icon {
        font-size: 12rem;
    }

    .skills-grid {
        grid-template-columns: repeat(auto-fill, minmax(120px, 1fr));
        gap: 15px;
        margin-top: 20px;
    }

    .skill-card {
        padding: 15px;
    }

    .skill-card i {
        font-size: 2.5rem;
        margin-bottom: 10px;
    }

    .skill-card h3 {
        font-size: 1.4rem;
    }

    /* Contact section */
    #contact {
        padding: 80px 0;
    }

    .contact-container {
        gap: 30px;
        margin-top: 30px;
    }

    .contact-card {
        padding: 25px 20px;
        gap: 15px;
    }

    .contact-icon {
        width: 60px;
        height: 60px;
        font-size: 2rem;
    }

    .contact-details h3 {
        font-size: 1.8rem;
        margin-bottom: 8px;
    }

    .contact-details p {
        font-size: 1.4rem;
        margin-bottom: 8px;
    }

    .contact-details a {
        font-size: 1.3rem;
    }

    .contact-form-container {
        padding: 30px 20px;
    }

    .contact-form-container h3 {
        font-size: 2.2rem;
        margin-bottom: 20px;
    }

    .form-group label {
        font-size: 1.3rem;
    }

    .form-control {
        padding: 14px 16px;
        font-size: 1.4rem;
    }

    .submit-btn {
        padding: 14px;
        font-size: 1.5rem;
    }

    /* Footer */
    #footer {
        padding: 40px 0 15px;
    }

    #footer .brand h1 {
        font-size: 2.5rem;
        margin-bottom: 15px;
    }

    #footer h2 {
        font-size: 1.6rem;
        margin-bottom: 20px;
    }

    #footer .social-item {
        width: 45px;
        height: 45px;
    }

    #footer .social-item i {
        font-size: 1.8rem;
    }

    #footer p {
        font-size: 1.3rem;
    }

    /* Theme toggle */
    .theme-toggle-container {
        top: 8px;
        right: 8px;
        padding: 5px 8px;
    }

    .theme-toggle {
        width: 50px;
        height: 25px;
    }

    .toggle-slider {
        width: 18px;
        height: 18px;
        top: 2px;
        left: 2px;
    }

    .light-mode .toggle-slider {
        transform: translateX(24px);
    }

    .theme-label {
        display: none;
    }
}

/* Ultra-small screens (phones under 240px) */
@media (max-width: 240px) {
    /* Header adjustments */
    #header .brand h1 {
        font-size: 1.6rem;
    }

    #header .nav-list ul a {
        font-size: 1.6rem;
        padding: 12px;
    }

    /* Hero section ultra-small adjustments */
    #hero {
        padding: 50px 6px 20px;
    }

    .hero-content {
        gap: 15px;
    }

    .name-letter {
        font-size: 1.8rem;
        font-weight: 600;
    }

    #hero h1 {
        font-size: 1.6rem;
        margin-bottom: 8px;
    }

    .name-container {
        gap: 0.5px;
        margin: 10px 0;
        transform: scale(0.85);
    }

    #hero p {
        font-size: 1.2rem;
        line-height: 1.4;
        margin: 0 auto 15px;
        padding: 0 6px;
    }

    .hero-buttons {
        gap: 10px;
        margin-top: 15px;
    }

    .cta {
        padding: 8px 16px;
        font-size: 1.3rem;
        max-width: 180px;
        margin: 2px 0;
    }

    .hero-image-container {
        max-width: 160px;
    }

    .image-frame {
        max-width: 140px;
        height: 140px;
    }

    /* Section titles */
    .section-title {
        font-size: 1.8rem;
        margin-bottom: 20px;
    }

    .section-title:after {
        width: 50px;
        height: 2px;
        bottom: -6px;
    }

    /* Services section */
    #services {
        padding: 50px 0;
    }

    #services .service-item {
        padding: 25px 15px;
    }

    #services .service-item h2 {
        font-size: 1.6rem;
        margin-bottom: 10px;
    }

    #services .service-item p {
        font-size: 1.2rem;
    }

    /* Projects section */
    #projects {
        padding: 50px 0;
    }

    #projects .project-info {
        padding: 20px 15px;
    }

    #projects .project-info h1 {
        font-size: 1.8rem;
        margin-bottom: 6px;
    }

    #projects .project-info p {
        font-size: 1.2rem;
        margin-bottom: 12px;
    }

    .tech-tags span {
        font-size: 1rem;
        padding: 3px 10px;
    }

    .project-links a {
        font-size: 1.2rem;
        padding: 5px 12px;
    }

    /* About section */
    #about {
        padding: 50px 0;
    }

    #about .about {
        gap: 25px;
    }

    #about .about-img {
        max-width: 250px;
        height: 350px;
    }

    .profile-icon {
        font-size: 10rem;
    }

    .skills-grid {
        grid-template-columns: repeat(auto-fill, minmax(100px, 1fr));
        gap: 12px;
        margin-top: 15px;
    }

    .skill-card {
        padding: 12px;
    }

    .skill-card i {
        font-size: 2rem;
        margin-bottom: 8px;
    }

    .skill-card h3 {
        font-size: 1.2rem;
    }

    /* Contact section */
    #contact {
        padding: 60px 0;
    }

    .contact-container {
        gap: 25px;
        margin-top: 25px;
    }

    .contact-card {
        padding: 20px 15px;
        gap: 12px;
    }

    .contact-icon {
        width: 50px;
        height: 50px;
        font-size: 1.8rem;
    }

    .contact-details h3 {
        font-size: 1.6rem;
        margin-bottom: 6px;
    }

    .contact-details p {
        font-size: 1.2rem;
        margin-bottom: 6px;
    }

    .contact-details a {
        font-size: 1.2rem;
    }

    .contact-form-container {
        padding: 25px 15px;
    }

    .contact-form-container h3 {
        font-size: 1.8rem;
        margin-bottom: 15px;
    }

    .form-group label {
        font-size: 1.2rem;
    }

    .form-control {
        padding: 12px 14px;
        font-size: 1.2rem;
    }

    .submit-btn {
        padding: 12px;
        font-size: 1.3rem;
    }

    /* Footer */
    #footer {
        padding: 30px 0 12px;
    }

    #footer .brand h1 {
        font-size: 2rem;
        margin-bottom: 12px;
    }

    #footer h2 {
        font-size: 1.4rem;
        margin-bottom: 15px;
    }

    #footer .social-item {
        width: 40px;
        height: 40px;
    }

    #footer .social-item i {
        font-size: 1.6rem;
    }

    #footer p {
        font-size: 1.2rem;
    }

    /* Theme toggle */
    .theme-toggle-container {
        top: 6px;
        right: 6px;
        padding: 4px 6px;
    }

    .theme-toggle {
        width: 45px;
        height: 22px;
    }

    .toggle-slider {
        width: 16px;
        height: 16px;
        top: 2px;
        left: 2px;
    }

    .light-mode .toggle-slider {
        transform: translateX(21px);
    }

    /* Container adjustments */
    .container {
        padding: 0 5px;
    }

    /* General spacing adjustments */
    #services .services {
        padding: 0 10px;
    }

    #projects .projects {
        padding: 0 10px;
    }

    #about .about {
        padding: 0 10px;
    }

    #contact .contact {
        padding: 0 10px;
    }

    #footer .footer {
        padding: 0 10px;
    }
}

/* Extremely small screens (phones under 200px) */
@media (max-width: 200px) {
    /* Header adjustments */
    #header .brand h1 {
        font-size: 1.4rem;
    }

    #header .nav-list ul a {
        font-size: 1.4rem;
        padding: 10px;
    }

    /* Hero section adjustments for very small screens */
    #hero {
        padding: 40px 4px 15px;
    }

    .hero-content {
        gap: 10px;
    }

    .name-letter {
        font-size: 1.4rem;
        font-weight: 600;
    }

    #hero h1 {
        font-size: 1.4rem;
        margin-bottom: 6px;
    }

    .name-container {
        gap: 0.3px;
        margin: 8px 0;
        transform: scale(0.75);
    }

    #hero p {
        font-size: 1rem;
        line-height: 1.3;
        margin: 0 auto 12px;
        padding: 0 4px;
    }

    .hero-buttons {
        gap: 8px;
        margin-top: 12px;
    }

    .cta {
        padding: 6px 12px;
        font-size: 1.1rem;
        max-width: 150px;
        margin: 1px 0;
    }

    .hero-image-container {
        max-width: 120px;
    }

    .image-frame {
        max-width: 100px;
        height: 100px;
    }

    /* Section titles */
    .section-title {
        font-size: 1.6rem;
        margin-bottom: 15px;
    }

    .section-title:after {
        width: 40px;
        height: 2px;
        bottom: -5px;
    }

    /* Services section */
    #services {
        padding: 40px 0;
    }

    #services .service-item {
        padding: 20px 12px;
    }

    #services .service-item h2 {
        font-size: 1.4rem;
        margin-bottom: 8px;
    }

    #services .service-item p {
        font-size: 1rem;
    }

    /* Projects section */
    #projects {
        padding: 40px 0;
    }

    #projects .project-info {
        padding: 15px 12px;
    }

    #projects .project-info h1 {
        font-size: 1.6rem;
        margin-bottom: 5px;
    }

    #projects .project-info p {
        font-size: 1rem;
        margin-bottom: 10px;
    }

    .tech-tags span {
        font-size: 0.9rem;
        padding: 2px 8px;
    }

    .project-links a {
        font-size: 1rem;
        padding: 4px 10px;
    }

    /* About section */
    #about {
        padding: 40px 0;
    }

    #about .about {
        gap: 20px;
    }

    #about .about-img {
        max-width: 200px;
        height: 280px;
    }

    .profile-icon {
        font-size: 8rem;
    }

    .skills-grid {
        grid-template-columns: repeat(auto-fill, minmax(80px, 1fr));
        gap: 10px;
        margin-top: 12px;
    }

    .skill-card {
        padding: 10px;
    }

    .skill-card i {
        font-size: 1.8rem;
        margin-bottom: 6px;
    }

    .skill-card h3 {
        font-size: 1rem;
    }

    /* Contact section */
    #contact {
        padding: 50px 0;
    }

    .contact-container {
        gap: 20px;
        margin-top: 20px;
    }

    .contact-card {
        padding: 15px 12px;
        gap: 10px;
    }

    .contact-icon {
        width: 40px;
        height: 40px;
        font-size: 1.6rem;
    }

    .contact-details h3 {
        font-size: 1.4rem;
        margin-bottom: 5px;
    }

    .contact-details p {
        font-size: 1rem;
        margin-bottom: 5px;
    }

    .contact-details a {
        font-size: 1rem;
    }

    .contact-form-container {
        padding: 20px 12px;
    }

    .contact-form-container h3 {
        font-size: 1.6rem;
        margin-bottom: 12px;
    }

    .form-group label {
        font-size: 1rem;
    }

    .form-control {
        padding: 10px 12px;
        font-size: 1rem;
    }

    .submit-btn {
        padding: 10px;
        font-size: 1.1rem;
    }

    /* Footer */
    #footer {
        padding: 25px 0 10px;
    }

    #footer .brand h1 {
        font-size: 1.8rem;
        margin-bottom: 10px;
    }

    #footer h2 {
        font-size: 1.2rem;
        margin-bottom: 12px;
    }

    #footer .social-item {
        width: 35px;
        height: 35px;
    }

    #footer .social-item i {
        font-size: 1.4rem;
    }

    #footer p {
        font-size: 1rem;
    }

    /* Theme toggle */
    .theme-toggle-container {
        top: 5px;
        right: 5px;
        padding: 3px 5px;
    }

    .theme-toggle {
        width: 40px;
        height: 20px;
    }

    .toggle-slider {
        width: 14px;
        height: 14px;
        top: 2px;
        left: 2px;
    }

    .light-mode .toggle-slider {
        transform: translateX(18px);
    }

    /* Container adjustments */
    .container {
        padding: 0 3px;
    }

    /* General spacing adjustments */
    #services .services {
        padding: 0 8px;
    }

    #projects .projects {
        padding: 0 8px;
    }

    #about .about {
        padding: 0 8px;
    }

    #contact .contact {
        padding: 0 8px;
    }

    #footer .footer {
        padding: 0 8px;
    }
}

/* Ultra-extreme small screens (phones under 180px) */
@media (max-width: 180px) {
    /* Header adjustments */
    #header .brand h1 {
        font-size: 1.2rem;
    }

    #header .nav-list ul a {
        font-size: 1.2rem;
        padding: 8px;
    }

    /* Hero section adjustments for extremely small screens */
    #hero {
        padding: 30px 3px 10px;
    }

    .hero-content {
        gap: 8px;
    }

    .name-letter {
        font-size: 1.2rem;
        font-weight: 600;
    }

    #hero h1 {
        font-size: 1.2rem;
        margin-bottom: 5px;
    }

    .name-container {
        gap: 0.2px;
        margin: 6px 0;
        transform: scale(0.65);
    }

    #hero p {
        font-size: 0.9rem;