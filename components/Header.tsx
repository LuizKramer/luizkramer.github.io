import { MobileNav, ThemeToggle } from "./ThemeControls";
import Image from "next/image";
const links = [{href:"#sobre",label:"Sobre"},{href:"#experiencia",label:"Experiência"},{href:"#projetos",label:"Projetos"},{href:"#tecnologias",label:"Tecnologias"},{href:"#contato",label:"Contato"}] as const;
export function Header(){return <header className="site-header"><a className="brand-logo" href="#inicio" aria-label="Luiz Kramer — ir para o início"><Image src="/logo-lk-mark.png" alt="" width={1254} height={1254} priority/><span>Luiz Kramer</span></a><nav className="desktop-nav" aria-label="Navegação principal">{links.map(l=><a key={l.href} href={l.href}>{l.label}</a>)}</nav><div className="header-actions"><ThemeToggle/><MobileNav links={links}/></div></header>}
